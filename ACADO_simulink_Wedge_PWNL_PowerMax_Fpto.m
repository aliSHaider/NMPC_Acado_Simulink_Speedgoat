%% Description : Implementation of NLPMC for WedgeGlobal's WEC-PTO
%  Using ACADO toolkit
%  Design Type: Piecewise (PW) Nonlinear Cost Index
%% This Code has 5 Sections.
%% Note: This file has to run successfully for Simulink model to work.
%% Author: Ali S. Haider at Oregon State University
%% Date Last Modified: Sept 23, 2020.
%% ===============> Code SECTION 1 <===============
%==> House cleaning and ACADO compiler setting
clc; 
clear all;
close all;
format compact;
COMPILE = 1;   % Compile Acado MPC code ON
EXPORT = 1;    % Export Acado MPC s-function code ON
%% ===============> Code SECTION 2 <===============
% Nonlinear Frequency Dependent WEC Model Paramerters and SS model for Simulation
%==> Define constants
caa=252700;
cab=0;
cba=1;
cbb=3.8;
cbc=3.61;
Ainf=3.3e5;
m=9.7e4;
k=8.8e5;
M=m+Ainf;
%==> Define Sample time
Ts = 0.1;
%==> Continuous time WEC Plant model and conversion to discrete form
% continuous time state space WEC model
Ac =[0           -k/M                1/M           0
     1             0                 0             0
    -caa/cba     -cab/cba          -cbb/cba    -cbc/cba
     0             0                 1             0     ];
Bc= [-1/M  1/M
      0    0
      0    0
      0    0 ];
Cc = [1    0     0   0
      0    1     0   0];
Dc = zeros(2);
%discrete time state space WEC model, 
sysc=ss(Ac,Bc,Cc,Dc);
sysd=c2d(sysc,Ts);
Ad=sysd.A;
Bd=sysd.B;
Cd=sysd.C;
Dd=sysd.D;
% delete temporary variables.
clear Ac Bc* Cc Dc sysc sysd
%% ===============> Code SECTION 3 <===============
% Defining Nonlinear Plant model to be embedded in Acado NLMPC
%==> Define Variable roles
Disturbance Fe;
DifferentialState v z Fr F Fp1;
Control dFp1;     
%==> Differential Equation Model
%    each f(i) defines the derivative of state variables, where i represent
%    the position number of states in state declaration command
%    'Differential State', i.e. Fr is third in that list so f(3) is
%    derivative of Fr.
f(1) = z*(-1*k/M) + Fr*1/M  +  -1*Fp1*1/M   + Fe*1/M;
f(2) = v;
f(3) = v*(-1*caa/cba)  + z*(-1*cab/cba) +  Fr*(-1*cbb/cba) + F*(-1*cbc/cba);
f(4) = Fr;
f(5) = dFp1;
%% ===============> Code SECTION 4 <===============
%==> Define Cost function variable vectors h and hN
h = [Fp1^2,Fp1,v,1];
hN = [v];
%==> Name the problem as 'mpc'
acadoSet('problemname', 'mpc');
%==> Setting Prediction Horizon
N = 4; % No. of time samples that controller will predict.
ocp = acado.OCP( 0.0, N*Ts, N );
%==> Setting Quadratic Cost function Weights, **dummy values just
    % for problem Initialization. Only sizes need to be correct. Actual
    % weighing matrices are defined in Section 5
W = acado.BMatrix(eye(length(h)));
WN = acado.BMatrix(eye(length(hN)));
%==> Setting optimization type: LSQ=least square quadratic
ocp.minimizeLSQ( W, h );
ocp.minimizeLSQEndTerm( WN, hN );
%==> Setting bounds
ocp.subjectTo( -2  <= v  <= 2);
ocp.subjectTo(  -10e6 <= Fp1 <= 10e6 );
%==> setting dynamic model from section-1 as an internal dynamic system
ocp.setModel(f);
%==> Export MPC files that will be used by the Simulink Model
%    and setting the optimization algorithm 
mpc = acado.OCPexport( ocp );
mpc.set( 'HESSIAN_APPROXIMATION',       'GAUSS_NEWTON'   );
mpc.set( 'DISCRETIZATION_TYPE',         'MULTIPLE_SHOOTING' );
mpc.set( 'SPARSE_QP_SOLUTION',          'FULL_CONDENSING_N2');
mpc.set( 'INTEGRATOR_TYPE',             'INT_RK45'       );
mpc.set( 'NUM_INTEGRATOR_STEPS',         N               );
mpc.set( 'QP_SOLVER',                   'QP_QPOASES3'    );
mpc.set( 'LEVENBERG_MARQUARDT',          1e-4            );
% Import necessery Acado files in current directory for compilation
if EXPORT
    mpc.exportCode( 'export_MPC' );
end
if COMPILE
    global ACADO_;
    copyfile([ACADO_.pwd '/../../external_packages/qpoases3'],...
             'export_MPC/qpoases3')
    copyfile('export_MPC/*', cd)
    make_custom_solver_sfunction
end
%% ===============> Code SECTION 5 <===============
%==> initializing values for the state variables
X0 = zeros(1,length(f));
Xref = [zeros(1,length(f))]
%==> initializing values for outputs
y = [repmat(zeros(1,length(h)-1),N,1) zeros(N,1)].';
yN = zeros(1,length(hN)).';
%==> Ppto cost function constant parameters
eta= 0.94; %converter efficiency
c10=9.271331158e-1;
c11=2.986818189e-7;
c12=1.64275e-6;
c13=7.076786316e-2;
c14=1.385728e2;
c15=7.62150425e2;

c20=9.130091884e-1;
c21=1551/10448;

c30=9.669908116e-1;
c40=9.528668842e-1;

% Weight Scheduling matrices for minimization problem.
% Consult Documentation for the details 
% factor of 2 is to cancel 1/2 factor built into ACADO algorithm.
% remember h = [Fp1^2,Fp1,v,1] and Pelect_2=(1/2)*h*(Whi)*h'

%        Fp^2      Fp      vp      1     
Wh1 = 2*[0         0      -c11/2   0       % Fp^2
         0         c12    -c10/2  -c13/2   % Fp
        -c11/2    -c10/2   0      -c14/2   % vp
         0        -c13/2  -c14/2   c15 ];  % 1 
  
%        Fp^2      Fp      vp      1     
Wh4 = 2*[0         0      -c11/2   0       % Fp^2
         0         c12    -c40/2   c13/2   % Fp
        -c11/2    -c40/2   0      -c14/2   % vp
         0         c13/2  -c14/2   c15 ];  % 1 

%        Fp^2      Fp      vp      1     
Wh2 = 2*[0         0       0       0       % Fp^2
         0         0      -c20/2  -c21/2   % Fp
         0        -c20/2   0       0       % vp
         0        -c21/2   0       0 ];    % 1 
  
%        Fp^2      Fp      vp      1     
Wh3 = 2*[0         0       0       0       % Fp^2
         0         0      -c30/2   c21/2   % Fp
         0        -c30/2   0       0       % vp
         0         c21/2   0       0 ];    % 1 
  
%==> No terminal penalty
WN = diag(zeros(1,length(hN)));
%==> Simulink Acado s-function Block's initialization values
xInit = X0.';
zInit = 0;
uInit = 0;
yref = [y(:);yN(:)];
Wmat = Wh1;
WNmat = WN;
x0 = X0.';
bValues = [];  % bound values are fixed in the generated code

Fk=13893.63 ;  % Fpto switching value, needed for weight scheduling
%==> Load excitation force profile for simulation
load Fext.mat
