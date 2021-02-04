%% Description :Wedge-Global's Machine WEC-PTO Characteristics and Plots
%% Author: Ali S. Haider at Oregon State University
%% Date Last Modified: Sept 23, 2020.
% House cleaning
clc,clear
format compact
close all
%% Section#1: PTO-Current(Arms) Vs PTO-Force (N)
%  From Ipto vs Fpto data provided by Wedge-Global

Fpto=-10e4:1000:10e4;
Fk=13895 ;
L=length(Fpto);
for i=1:L
    
   if Fpto(i) <= -Fk
       Ipto(i)=(Fpto(i)-21539.45)/307.27;
   end
   
   if  -Fk < Fpto(i) &&  Fpto(i) < 0
       Ipto(i)=-sqrt(-Fpto(i)/1.0448);
   end
   
   if  0 <= Fpto(i) &&  Fpto(i) < Fk
       Ipto(i)=sqrt(Fpto(i)/1.0448);
   end
   
   if  Fpto(i) >= Fk
       Ipto(i)=(Fpto(i)+21539.45)/307.27;
   end
   
end

plot(Fpto,Ipto,'k','LineWidth',2)
xlabel('F_{pto}(N)'), ylabel('I_{pto}(A_{rms})')
title('PTO-Current vs. PTO-Force Data')
legend('Experimental Data')
grid on

%% Section#2: PTO-Current(Arms) Vs PTO-Force (N)
%  Individual Curves provided by Wedge-Global

plot(Fpto,Ipto,'.k','MarkerSize',12),grid
hold on


Ipto1=(Fpto-21539.45)/307.27;
Ipto4=(Fpto+21539.45)/307.27;
Ipto2=-sqrt(abs(Fpto)/1.0448);
Ipto3=sqrt(abs(Fpto)/1.0448);

plot(Fpto,Ipto1,'g','LineWidth',1.25)
plot(-abs(Fpto),Ipto2,'c','LineWidth',1.25)
plot(abs(Fpto),Ipto3,'r','LineWidth',1.25)
plot(Fpto,Ipto4,'m','LineWidth',1.25)

line([-Fk,-Fk],[-400 400],'Color','black','LineStyle','--')
line([0,0],[-400 400],'Color','black','LineStyle','--')
line([Fk,Fk],[-400 400],'Color','black','LineStyle','--')                

hold off


xlabel('F_{pto}(N)'), ylabel('I_{pto}(A_{rms})')
title('PTO-Current vs. PTO-Force Data')
legend('Experimental Data','Domain 1 Linear fit','Domain 2 Curve fit',...
    'Domain 3 Curve fit','Domain 4 linear fit','Force domain Separators')




