/*
 *    This file was auto-generated using the ACADO Toolkit.
 *    
 *    While ACADO Toolkit is free software released under the terms of
 *    the GNU Lesser General Public License (LGPL), the generated code
 *    as such remains the property of the user who used ACADO Toolkit
 *    to generate this code. In particular, user dependent data of the code
 *    do not inherit the GNU LGPL license. On the other hand, parts of the
 *    generated code that are a direct copy of source code from the
 *    ACADO Toolkit or the software tools it is based on, remain, as derived
 *    work, automatically covered by the LGPL license.
 *    
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *    
 */


#include "acado_common.h"




/******************************************************************************/
/*                                                                            */
/* ACADO code generation                                                      */
/*                                                                            */
/******************************************************************************/


int acado_modelSimulation(  )
{
int ret;

int lRun1;
ret = 0;
for (lRun1 = 0; lRun1 < 4; ++lRun1)
{
acadoWorkspace.state[0] = acadoVariables.x[lRun1 * 5];
acadoWorkspace.state[1] = acadoVariables.x[lRun1 * 5 + 1];
acadoWorkspace.state[2] = acadoVariables.x[lRun1 * 5 + 2];
acadoWorkspace.state[3] = acadoVariables.x[lRun1 * 5 + 3];
acadoWorkspace.state[4] = acadoVariables.x[lRun1 * 5 + 4];

acadoWorkspace.state[35] = acadoVariables.u[lRun1];

ret = acado_integrate(acadoWorkspace.state, 1);

acadoWorkspace.d[lRun1 * 5] = acadoWorkspace.state[0] - acadoVariables.x[lRun1 * 5 + 5];
acadoWorkspace.d[lRun1 * 5 + 1] = acadoWorkspace.state[1] - acadoVariables.x[lRun1 * 5 + 6];
acadoWorkspace.d[lRun1 * 5 + 2] = acadoWorkspace.state[2] - acadoVariables.x[lRun1 * 5 + 7];
acadoWorkspace.d[lRun1 * 5 + 3] = acadoWorkspace.state[3] - acadoVariables.x[lRun1 * 5 + 8];
acadoWorkspace.d[lRun1 * 5 + 4] = acadoWorkspace.state[4] - acadoVariables.x[lRun1 * 5 + 9];

acadoWorkspace.evGx[lRun1 * 25] = acadoWorkspace.state[5];
acadoWorkspace.evGx[lRun1 * 25 + 1] = acadoWorkspace.state[6];
acadoWorkspace.evGx[lRun1 * 25 + 2] = acadoWorkspace.state[7];
acadoWorkspace.evGx[lRun1 * 25 + 3] = acadoWorkspace.state[8];
acadoWorkspace.evGx[lRun1 * 25 + 4] = acadoWorkspace.state[9];
acadoWorkspace.evGx[lRun1 * 25 + 5] = acadoWorkspace.state[10];
acadoWorkspace.evGx[lRun1 * 25 + 6] = acadoWorkspace.state[11];
acadoWorkspace.evGx[lRun1 * 25 + 7] = acadoWorkspace.state[12];
acadoWorkspace.evGx[lRun1 * 25 + 8] = acadoWorkspace.state[13];
acadoWorkspace.evGx[lRun1 * 25 + 9] = acadoWorkspace.state[14];
acadoWorkspace.evGx[lRun1 * 25 + 10] = acadoWorkspace.state[15];
acadoWorkspace.evGx[lRun1 * 25 + 11] = acadoWorkspace.state[16];
acadoWorkspace.evGx[lRun1 * 25 + 12] = acadoWorkspace.state[17];
acadoWorkspace.evGx[lRun1 * 25 + 13] = acadoWorkspace.state[18];
acadoWorkspace.evGx[lRun1 * 25 + 14] = acadoWorkspace.state[19];
acadoWorkspace.evGx[lRun1 * 25 + 15] = acadoWorkspace.state[20];
acadoWorkspace.evGx[lRun1 * 25 + 16] = acadoWorkspace.state[21];
acadoWorkspace.evGx[lRun1 * 25 + 17] = acadoWorkspace.state[22];
acadoWorkspace.evGx[lRun1 * 25 + 18] = acadoWorkspace.state[23];
acadoWorkspace.evGx[lRun1 * 25 + 19] = acadoWorkspace.state[24];
acadoWorkspace.evGx[lRun1 * 25 + 20] = acadoWorkspace.state[25];
acadoWorkspace.evGx[lRun1 * 25 + 21] = acadoWorkspace.state[26];
acadoWorkspace.evGx[lRun1 * 25 + 22] = acadoWorkspace.state[27];
acadoWorkspace.evGx[lRun1 * 25 + 23] = acadoWorkspace.state[28];
acadoWorkspace.evGx[lRun1 * 25 + 24] = acadoWorkspace.state[29];

acadoWorkspace.evGu[lRun1 * 5] = acadoWorkspace.state[30];
acadoWorkspace.evGu[lRun1 * 5 + 1] = acadoWorkspace.state[31];
acadoWorkspace.evGu[lRun1 * 5 + 2] = acadoWorkspace.state[32];
acadoWorkspace.evGu[lRun1 * 5 + 3] = acadoWorkspace.state[33];
acadoWorkspace.evGu[lRun1 * 5 + 4] = acadoWorkspace.state[34];
}
return ret;
}

void acado_evaluateLSQ(const real_t* in, real_t* out)
{
const real_t* xd = in;
/* Vector of auxiliary variables; number of elements: 7. */
real_t* a = acadoWorkspace.objAuxVar;

/* Compute intermediate quantities: */
a[0] = ((xd[4])*(xd[4]));
a[1] = (real_t)(0.0000000000000000e+00);
a[2] = (real_t)(0.0000000000000000e+00);
a[3] = (real_t)(0.0000000000000000e+00);
a[4] = (real_t)(0.0000000000000000e+00);
a[5] = ((real_t)(2.0000000000000000e+00)*xd[4]);
a[6] = (real_t)(0.0000000000000000e+00);

/* Compute outputs: */
out[0] = a[0];
out[1] = xd[4];
out[2] = xd[0];
out[3] = (real_t)(1.0000000000000000e+00);
out[4] = a[1];
out[5] = a[2];
out[6] = a[3];
out[7] = a[4];
out[8] = a[5];
out[9] = (real_t)(0.0000000000000000e+00);
out[10] = (real_t)(0.0000000000000000e+00);
out[11] = (real_t)(0.0000000000000000e+00);
out[12] = (real_t)(0.0000000000000000e+00);
out[13] = (real_t)(1.0000000000000000e+00);
out[14] = (real_t)(1.0000000000000000e+00);
out[15] = (real_t)(0.0000000000000000e+00);
out[16] = (real_t)(0.0000000000000000e+00);
out[17] = (real_t)(0.0000000000000000e+00);
out[18] = (real_t)(0.0000000000000000e+00);
out[19] = (real_t)(0.0000000000000000e+00);
out[20] = (real_t)(0.0000000000000000e+00);
out[21] = (real_t)(0.0000000000000000e+00);
out[22] = (real_t)(0.0000000000000000e+00);
out[23] = (real_t)(0.0000000000000000e+00);
out[24] = a[6];
out[25] = (real_t)(0.0000000000000000e+00);
out[26] = (real_t)(0.0000000000000000e+00);
out[27] = (real_t)(0.0000000000000000e+00);
}

void acado_evaluateLSQEndTerm(const real_t* in, real_t* out)
{
const real_t* xd = in;

/* Compute outputs: */
out[0] = xd[0];
}

void acado_setObjQ1Q2( real_t* const tmpFx, real_t* const tmpObjS, real_t* const tmpQ1, real_t* const tmpQ2 )
{
tmpQ2[0] = + tmpFx[0]*tmpObjS[0] + tmpFx[5]*tmpObjS[4] + tmpFx[10]*tmpObjS[8] + tmpFx[15]*tmpObjS[12];
tmpQ2[1] = + tmpFx[0]*tmpObjS[1] + tmpFx[5]*tmpObjS[5] + tmpFx[10]*tmpObjS[9] + tmpFx[15]*tmpObjS[13];
tmpQ2[2] = + tmpFx[0]*tmpObjS[2] + tmpFx[5]*tmpObjS[6] + tmpFx[10]*tmpObjS[10] + tmpFx[15]*tmpObjS[14];
tmpQ2[3] = + tmpFx[0]*tmpObjS[3] + tmpFx[5]*tmpObjS[7] + tmpFx[10]*tmpObjS[11] + tmpFx[15]*tmpObjS[15];
tmpQ2[4] = + tmpFx[1]*tmpObjS[0] + tmpFx[6]*tmpObjS[4] + tmpFx[11]*tmpObjS[8] + tmpFx[16]*tmpObjS[12];
tmpQ2[5] = + tmpFx[1]*tmpObjS[1] + tmpFx[6]*tmpObjS[5] + tmpFx[11]*tmpObjS[9] + tmpFx[16]*tmpObjS[13];
tmpQ2[6] = + tmpFx[1]*tmpObjS[2] + tmpFx[6]*tmpObjS[6] + tmpFx[11]*tmpObjS[10] + tmpFx[16]*tmpObjS[14];
tmpQ2[7] = + tmpFx[1]*tmpObjS[3] + tmpFx[6]*tmpObjS[7] + tmpFx[11]*tmpObjS[11] + tmpFx[16]*tmpObjS[15];
tmpQ2[8] = + tmpFx[2]*tmpObjS[0] + tmpFx[7]*tmpObjS[4] + tmpFx[12]*tmpObjS[8] + tmpFx[17]*tmpObjS[12];
tmpQ2[9] = + tmpFx[2]*tmpObjS[1] + tmpFx[7]*tmpObjS[5] + tmpFx[12]*tmpObjS[9] + tmpFx[17]*tmpObjS[13];
tmpQ2[10] = + tmpFx[2]*tmpObjS[2] + tmpFx[7]*tmpObjS[6] + tmpFx[12]*tmpObjS[10] + tmpFx[17]*tmpObjS[14];
tmpQ2[11] = + tmpFx[2]*tmpObjS[3] + tmpFx[7]*tmpObjS[7] + tmpFx[12]*tmpObjS[11] + tmpFx[17]*tmpObjS[15];
tmpQ2[12] = + tmpFx[3]*tmpObjS[0] + tmpFx[8]*tmpObjS[4] + tmpFx[13]*tmpObjS[8] + tmpFx[18]*tmpObjS[12];
tmpQ2[13] = + tmpFx[3]*tmpObjS[1] + tmpFx[8]*tmpObjS[5] + tmpFx[13]*tmpObjS[9] + tmpFx[18]*tmpObjS[13];
tmpQ2[14] = + tmpFx[3]*tmpObjS[2] + tmpFx[8]*tmpObjS[6] + tmpFx[13]*tmpObjS[10] + tmpFx[18]*tmpObjS[14];
tmpQ2[15] = + tmpFx[3]*tmpObjS[3] + tmpFx[8]*tmpObjS[7] + tmpFx[13]*tmpObjS[11] + tmpFx[18]*tmpObjS[15];
tmpQ2[16] = + tmpFx[4]*tmpObjS[0] + tmpFx[9]*tmpObjS[4] + tmpFx[14]*tmpObjS[8] + tmpFx[19]*tmpObjS[12];
tmpQ2[17] = + tmpFx[4]*tmpObjS[1] + tmpFx[9]*tmpObjS[5] + tmpFx[14]*tmpObjS[9] + tmpFx[19]*tmpObjS[13];
tmpQ2[18] = + tmpFx[4]*tmpObjS[2] + tmpFx[9]*tmpObjS[6] + tmpFx[14]*tmpObjS[10] + tmpFx[19]*tmpObjS[14];
tmpQ2[19] = + tmpFx[4]*tmpObjS[3] + tmpFx[9]*tmpObjS[7] + tmpFx[14]*tmpObjS[11] + tmpFx[19]*tmpObjS[15];
tmpQ1[0] = + tmpQ2[0]*tmpFx[0] + tmpQ2[1]*tmpFx[5] + tmpQ2[2]*tmpFx[10] + tmpQ2[3]*tmpFx[15];
tmpQ1[1] = + tmpQ2[0]*tmpFx[1] + tmpQ2[1]*tmpFx[6] + tmpQ2[2]*tmpFx[11] + tmpQ2[3]*tmpFx[16];
tmpQ1[2] = + tmpQ2[0]*tmpFx[2] + tmpQ2[1]*tmpFx[7] + tmpQ2[2]*tmpFx[12] + tmpQ2[3]*tmpFx[17];
tmpQ1[3] = + tmpQ2[0]*tmpFx[3] + tmpQ2[1]*tmpFx[8] + tmpQ2[2]*tmpFx[13] + tmpQ2[3]*tmpFx[18];
tmpQ1[4] = + tmpQ2[0]*tmpFx[4] + tmpQ2[1]*tmpFx[9] + tmpQ2[2]*tmpFx[14] + tmpQ2[3]*tmpFx[19];
tmpQ1[5] = + tmpQ2[4]*tmpFx[0] + tmpQ2[5]*tmpFx[5] + tmpQ2[6]*tmpFx[10] + tmpQ2[7]*tmpFx[15];
tmpQ1[6] = + tmpQ2[4]*tmpFx[1] + tmpQ2[5]*tmpFx[6] + tmpQ2[6]*tmpFx[11] + tmpQ2[7]*tmpFx[16];
tmpQ1[7] = + tmpQ2[4]*tmpFx[2] + tmpQ2[5]*tmpFx[7] + tmpQ2[6]*tmpFx[12] + tmpQ2[7]*tmpFx[17];
tmpQ1[8] = + tmpQ2[4]*tmpFx[3] + tmpQ2[5]*tmpFx[8] + tmpQ2[6]*tmpFx[13] + tmpQ2[7]*tmpFx[18];
tmpQ1[9] = + tmpQ2[4]*tmpFx[4] + tmpQ2[5]*tmpFx[9] + tmpQ2[6]*tmpFx[14] + tmpQ2[7]*tmpFx[19];
tmpQ1[10] = + tmpQ2[8]*tmpFx[0] + tmpQ2[9]*tmpFx[5] + tmpQ2[10]*tmpFx[10] + tmpQ2[11]*tmpFx[15];
tmpQ1[11] = + tmpQ2[8]*tmpFx[1] + tmpQ2[9]*tmpFx[6] + tmpQ2[10]*tmpFx[11] + tmpQ2[11]*tmpFx[16];
tmpQ1[12] = + tmpQ2[8]*tmpFx[2] + tmpQ2[9]*tmpFx[7] + tmpQ2[10]*tmpFx[12] + tmpQ2[11]*tmpFx[17];
tmpQ1[13] = + tmpQ2[8]*tmpFx[3] + tmpQ2[9]*tmpFx[8] + tmpQ2[10]*tmpFx[13] + tmpQ2[11]*tmpFx[18];
tmpQ1[14] = + tmpQ2[8]*tmpFx[4] + tmpQ2[9]*tmpFx[9] + tmpQ2[10]*tmpFx[14] + tmpQ2[11]*tmpFx[19];
tmpQ1[15] = + tmpQ2[12]*tmpFx[0] + tmpQ2[13]*tmpFx[5] + tmpQ2[14]*tmpFx[10] + tmpQ2[15]*tmpFx[15];
tmpQ1[16] = + tmpQ2[12]*tmpFx[1] + tmpQ2[13]*tmpFx[6] + tmpQ2[14]*tmpFx[11] + tmpQ2[15]*tmpFx[16];
tmpQ1[17] = + tmpQ2[12]*tmpFx[2] + tmpQ2[13]*tmpFx[7] + tmpQ2[14]*tmpFx[12] + tmpQ2[15]*tmpFx[17];
tmpQ1[18] = + tmpQ2[12]*tmpFx[3] + tmpQ2[13]*tmpFx[8] + tmpQ2[14]*tmpFx[13] + tmpQ2[15]*tmpFx[18];
tmpQ1[19] = + tmpQ2[12]*tmpFx[4] + tmpQ2[13]*tmpFx[9] + tmpQ2[14]*tmpFx[14] + tmpQ2[15]*tmpFx[19];
tmpQ1[20] = + tmpQ2[16]*tmpFx[0] + tmpQ2[17]*tmpFx[5] + tmpQ2[18]*tmpFx[10] + tmpQ2[19]*tmpFx[15];
tmpQ1[21] = + tmpQ2[16]*tmpFx[1] + tmpQ2[17]*tmpFx[6] + tmpQ2[18]*tmpFx[11] + tmpQ2[19]*tmpFx[16];
tmpQ1[22] = + tmpQ2[16]*tmpFx[2] + tmpQ2[17]*tmpFx[7] + tmpQ2[18]*tmpFx[12] + tmpQ2[19]*tmpFx[17];
tmpQ1[23] = + tmpQ2[16]*tmpFx[3] + tmpQ2[17]*tmpFx[8] + tmpQ2[18]*tmpFx[13] + tmpQ2[19]*tmpFx[18];
tmpQ1[24] = + tmpQ2[16]*tmpFx[4] + tmpQ2[17]*tmpFx[9] + tmpQ2[18]*tmpFx[14] + tmpQ2[19]*tmpFx[19];
}

void acado_setObjQN1QN2( real_t* const tmpObjSEndTerm, real_t* const tmpQN1, real_t* const tmpQN2 )
{
tmpQN2[0] = +tmpObjSEndTerm[0];
tmpQN2[1] = 0.0;
;
tmpQN2[2] = 0.0;
;
tmpQN2[3] = 0.0;
;
tmpQN2[4] = 0.0;
;
tmpQN1[0] = + tmpQN2[0];
tmpQN1[1] = 0.0;
;
tmpQN1[2] = 0.0;
;
tmpQN1[3] = 0.0;
;
tmpQN1[4] = 0.0;
;
tmpQN1[5] = + tmpQN2[1];
tmpQN1[6] = 0.0;
;
tmpQN1[7] = 0.0;
;
tmpQN1[8] = 0.0;
;
tmpQN1[9] = 0.0;
;
tmpQN1[10] = + tmpQN2[2];
tmpQN1[11] = 0.0;
;
tmpQN1[12] = 0.0;
;
tmpQN1[13] = 0.0;
;
tmpQN1[14] = 0.0;
;
tmpQN1[15] = + tmpQN2[3];
tmpQN1[16] = 0.0;
;
tmpQN1[17] = 0.0;
;
tmpQN1[18] = 0.0;
;
tmpQN1[19] = 0.0;
;
tmpQN1[20] = + tmpQN2[4];
tmpQN1[21] = 0.0;
;
tmpQN1[22] = 0.0;
;
tmpQN1[23] = 0.0;
;
tmpQN1[24] = 0.0;
;
}

void acado_evaluateObjective(  )
{
int runObj;
for (runObj = 0; runObj < 4; ++runObj)
{
acadoWorkspace.objValueIn[0] = acadoVariables.x[runObj * 5];
acadoWorkspace.objValueIn[1] = acadoVariables.x[runObj * 5 + 1];
acadoWorkspace.objValueIn[2] = acadoVariables.x[runObj * 5 + 2];
acadoWorkspace.objValueIn[3] = acadoVariables.x[runObj * 5 + 3];
acadoWorkspace.objValueIn[4] = acadoVariables.x[runObj * 5 + 4];
acadoWorkspace.objValueIn[5] = acadoVariables.u[runObj];

acado_evaluateLSQ( acadoWorkspace.objValueIn, acadoWorkspace.objValueOut );
acadoWorkspace.Dy[runObj * 4] = acadoWorkspace.objValueOut[0];
acadoWorkspace.Dy[runObj * 4 + 1] = acadoWorkspace.objValueOut[1];
acadoWorkspace.Dy[runObj * 4 + 2] = acadoWorkspace.objValueOut[2];
acadoWorkspace.Dy[runObj * 4 + 3] = acadoWorkspace.objValueOut[3];

acado_setObjQ1Q2( &(acadoWorkspace.objValueOut[ 4 ]), acadoVariables.W, &(acadoWorkspace.Q1[ runObj * 25 ]), &(acadoWorkspace.Q2[ runObj * 20 ]) );

}
acadoWorkspace.objValueIn[0] = acadoVariables.x[20];
acadoWorkspace.objValueIn[1] = acadoVariables.x[21];
acadoWorkspace.objValueIn[2] = acadoVariables.x[22];
acadoWorkspace.objValueIn[3] = acadoVariables.x[23];
acadoWorkspace.objValueIn[4] = acadoVariables.x[24];
acado_evaluateLSQEndTerm( acadoWorkspace.objValueIn, acadoWorkspace.objValueOut );

acadoWorkspace.DyN[0] = acadoWorkspace.objValueOut[0];

acado_setObjQN1QN2( acadoVariables.WN, acadoWorkspace.QN1, acadoWorkspace.QN2 );

}

void acado_multGxGu( real_t* const Gx1, real_t* const Gu1, real_t* const Gu2 )
{
Gu2[0] = + Gx1[0]*Gu1[0] + Gx1[1]*Gu1[1] + Gx1[2]*Gu1[2] + Gx1[3]*Gu1[3] + Gx1[4]*Gu1[4];
Gu2[1] = + Gx1[5]*Gu1[0] + Gx1[6]*Gu1[1] + Gx1[7]*Gu1[2] + Gx1[8]*Gu1[3] + Gx1[9]*Gu1[4];
Gu2[2] = + Gx1[10]*Gu1[0] + Gx1[11]*Gu1[1] + Gx1[12]*Gu1[2] + Gx1[13]*Gu1[3] + Gx1[14]*Gu1[4];
Gu2[3] = + Gx1[15]*Gu1[0] + Gx1[16]*Gu1[1] + Gx1[17]*Gu1[2] + Gx1[18]*Gu1[3] + Gx1[19]*Gu1[4];
Gu2[4] = + Gx1[20]*Gu1[0] + Gx1[21]*Gu1[1] + Gx1[22]*Gu1[2] + Gx1[23]*Gu1[3] + Gx1[24]*Gu1[4];
}

void acado_moveGuE( real_t* const Gu1, real_t* const Gu2 )
{
Gu2[0] = Gu1[0];
Gu2[1] = Gu1[1];
Gu2[2] = Gu1[2];
Gu2[3] = Gu1[3];
Gu2[4] = Gu1[4];
}

void acado_multBTW1( real_t* const Gu1, real_t* const Gu2, int iRow, int iCol )
{
acadoWorkspace.H[(iRow * 4) + (iCol)] = + Gu1[0]*Gu2[0] + Gu1[1]*Gu2[1] + Gu1[2]*Gu2[2] + Gu1[3]*Gu2[3] + Gu1[4]*Gu2[4];
}

void acado_multBTW1_R1( real_t* const Gu1, real_t* const Gu2, int iRow )
{
acadoWorkspace.H[iRow * 5] = + Gu1[0]*Gu2[0] + Gu1[1]*Gu2[1] + Gu1[2]*Gu2[2] + Gu1[3]*Gu2[3] + Gu1[4]*Gu2[4];
acadoWorkspace.H[iRow * 5] += 1.0000000000000000e-04;
}

void acado_multGxTGu( real_t* const Gx1, real_t* const Gu1, real_t* const Gu2 )
{
Gu2[0] = + Gx1[0]*Gu1[0] + Gx1[5]*Gu1[1] + Gx1[10]*Gu1[2] + Gx1[15]*Gu1[3] + Gx1[20]*Gu1[4];
Gu2[1] = + Gx1[1]*Gu1[0] + Gx1[6]*Gu1[1] + Gx1[11]*Gu1[2] + Gx1[16]*Gu1[3] + Gx1[21]*Gu1[4];
Gu2[2] = + Gx1[2]*Gu1[0] + Gx1[7]*Gu1[1] + Gx1[12]*Gu1[2] + Gx1[17]*Gu1[3] + Gx1[22]*Gu1[4];
Gu2[3] = + Gx1[3]*Gu1[0] + Gx1[8]*Gu1[1] + Gx1[13]*Gu1[2] + Gx1[18]*Gu1[3] + Gx1[23]*Gu1[4];
Gu2[4] = + Gx1[4]*Gu1[0] + Gx1[9]*Gu1[1] + Gx1[14]*Gu1[2] + Gx1[19]*Gu1[3] + Gx1[24]*Gu1[4];
}

void acado_multQEW2( real_t* const Q11, real_t* const Gu1, real_t* const Gu2, real_t* const Gu3 )
{
Gu3[0] = + Q11[0]*Gu1[0] + Q11[1]*Gu1[1] + Q11[2]*Gu1[2] + Q11[3]*Gu1[3] + Q11[4]*Gu1[4] + Gu2[0];
Gu3[1] = + Q11[5]*Gu1[0] + Q11[6]*Gu1[1] + Q11[7]*Gu1[2] + Q11[8]*Gu1[3] + Q11[9]*Gu1[4] + Gu2[1];
Gu3[2] = + Q11[10]*Gu1[0] + Q11[11]*Gu1[1] + Q11[12]*Gu1[2] + Q11[13]*Gu1[3] + Q11[14]*Gu1[4] + Gu2[2];
Gu3[3] = + Q11[15]*Gu1[0] + Q11[16]*Gu1[1] + Q11[17]*Gu1[2] + Q11[18]*Gu1[3] + Q11[19]*Gu1[4] + Gu2[3];
Gu3[4] = + Q11[20]*Gu1[0] + Q11[21]*Gu1[1] + Q11[22]*Gu1[2] + Q11[23]*Gu1[3] + Q11[24]*Gu1[4] + Gu2[4];
}

void acado_macATw1QDy( real_t* const Gx1, real_t* const w11, real_t* const w12, real_t* const w13 )
{
w13[0] = + Gx1[0]*w11[0] + Gx1[5]*w11[1] + Gx1[10]*w11[2] + Gx1[15]*w11[3] + Gx1[20]*w11[4] + w12[0];
w13[1] = + Gx1[1]*w11[0] + Gx1[6]*w11[1] + Gx1[11]*w11[2] + Gx1[16]*w11[3] + Gx1[21]*w11[4] + w12[1];
w13[2] = + Gx1[2]*w11[0] + Gx1[7]*w11[1] + Gx1[12]*w11[2] + Gx1[17]*w11[3] + Gx1[22]*w11[4] + w12[2];
w13[3] = + Gx1[3]*w11[0] + Gx1[8]*w11[1] + Gx1[13]*w11[2] + Gx1[18]*w11[3] + Gx1[23]*w11[4] + w12[3];
w13[4] = + Gx1[4]*w11[0] + Gx1[9]*w11[1] + Gx1[14]*w11[2] + Gx1[19]*w11[3] + Gx1[24]*w11[4] + w12[4];
}

void acado_macBTw1( real_t* const Gu1, real_t* const w11, real_t* const U1 )
{
U1[0] += + Gu1[0]*w11[0] + Gu1[1]*w11[1] + Gu1[2]*w11[2] + Gu1[3]*w11[3] + Gu1[4]*w11[4];
}

void acado_macQSbarW2( real_t* const Q11, real_t* const w11, real_t* const w12, real_t* const w13 )
{
w13[0] = + Q11[0]*w11[0] + Q11[1]*w11[1] + Q11[2]*w11[2] + Q11[3]*w11[3] + Q11[4]*w11[4] + w12[0];
w13[1] = + Q11[5]*w11[0] + Q11[6]*w11[1] + Q11[7]*w11[2] + Q11[8]*w11[3] + Q11[9]*w11[4] + w12[1];
w13[2] = + Q11[10]*w11[0] + Q11[11]*w11[1] + Q11[12]*w11[2] + Q11[13]*w11[3] + Q11[14]*w11[4] + w12[2];
w13[3] = + Q11[15]*w11[0] + Q11[16]*w11[1] + Q11[17]*w11[2] + Q11[18]*w11[3] + Q11[19]*w11[4] + w12[3];
w13[4] = + Q11[20]*w11[0] + Q11[21]*w11[1] + Q11[22]*w11[2] + Q11[23]*w11[3] + Q11[24]*w11[4] + w12[4];
}

void acado_macASbar( real_t* const Gx1, real_t* const w11, real_t* const w12 )
{
w12[0] += + Gx1[0]*w11[0] + Gx1[1]*w11[1] + Gx1[2]*w11[2] + Gx1[3]*w11[3] + Gx1[4]*w11[4];
w12[1] += + Gx1[5]*w11[0] + Gx1[6]*w11[1] + Gx1[7]*w11[2] + Gx1[8]*w11[3] + Gx1[9]*w11[4];
w12[2] += + Gx1[10]*w11[0] + Gx1[11]*w11[1] + Gx1[12]*w11[2] + Gx1[13]*w11[3] + Gx1[14]*w11[4];
w12[3] += + Gx1[15]*w11[0] + Gx1[16]*w11[1] + Gx1[17]*w11[2] + Gx1[18]*w11[3] + Gx1[19]*w11[4];
w12[4] += + Gx1[20]*w11[0] + Gx1[21]*w11[1] + Gx1[22]*w11[2] + Gx1[23]*w11[3] + Gx1[24]*w11[4];
}

void acado_expansionStep( real_t* const Gx1, real_t* const Gu1, real_t* const U1, real_t* const w11, real_t* const w12 )
{
w12[0] += + Gx1[0]*w11[0] + Gx1[1]*w11[1] + Gx1[2]*w11[2] + Gx1[3]*w11[3] + Gx1[4]*w11[4];
w12[1] += + Gx1[5]*w11[0] + Gx1[6]*w11[1] + Gx1[7]*w11[2] + Gx1[8]*w11[3] + Gx1[9]*w11[4];
w12[2] += + Gx1[10]*w11[0] + Gx1[11]*w11[1] + Gx1[12]*w11[2] + Gx1[13]*w11[3] + Gx1[14]*w11[4];
w12[3] += + Gx1[15]*w11[0] + Gx1[16]*w11[1] + Gx1[17]*w11[2] + Gx1[18]*w11[3] + Gx1[19]*w11[4];
w12[4] += + Gx1[20]*w11[0] + Gx1[21]*w11[1] + Gx1[22]*w11[2] + Gx1[23]*w11[3] + Gx1[24]*w11[4];
w12[0] += + Gu1[0]*U1[0];
w12[1] += + Gu1[1]*U1[0];
w12[2] += + Gu1[2]*U1[0];
w12[3] += + Gu1[3]*U1[0];
w12[4] += + Gu1[4]*U1[0];
}

void acado_copyHTH( int iRow, int iCol )
{
acadoWorkspace.H[(iRow * 4) + (iCol)] = acadoWorkspace.H[(iCol * 4) + (iRow)];
}

void acado_multRDy( real_t* const Dy1, real_t* const RDy1 )
{
RDy1[0] = 0.0;
;
}

void acado_multQDy( real_t* const Q2, real_t* const Dy1, real_t* const QDy1 )
{
QDy1[0] = + Q2[0]*Dy1[0] + Q2[1]*Dy1[1] + Q2[2]*Dy1[2] + Q2[3]*Dy1[3];
QDy1[1] = + Q2[4]*Dy1[0] + Q2[5]*Dy1[1] + Q2[6]*Dy1[2] + Q2[7]*Dy1[3];
QDy1[2] = + Q2[8]*Dy1[0] + Q2[9]*Dy1[1] + Q2[10]*Dy1[2] + Q2[11]*Dy1[3];
QDy1[3] = + Q2[12]*Dy1[0] + Q2[13]*Dy1[1] + Q2[14]*Dy1[2] + Q2[15]*Dy1[3];
QDy1[4] = + Q2[16]*Dy1[0] + Q2[17]*Dy1[1] + Q2[18]*Dy1[2] + Q2[19]*Dy1[3];
}

void acado_condensePrep(  )
{
/* Column: 0 */
acado_moveGuE( acadoWorkspace.evGu, acadoWorkspace.E );
acado_multGxGu( &(acadoWorkspace.evGx[ 25 ]), acadoWorkspace.E, &(acadoWorkspace.E[ 5 ]) );
acado_multGxGu( &(acadoWorkspace.evGx[ 50 ]), &(acadoWorkspace.E[ 5 ]), &(acadoWorkspace.E[ 10 ]) );
acado_multGxGu( &(acadoWorkspace.evGx[ 75 ]), &(acadoWorkspace.E[ 10 ]), &(acadoWorkspace.E[ 15 ]) );

acado_multGxGu( acadoWorkspace.QN1, &(acadoWorkspace.E[ 15 ]), acadoWorkspace.W1 );
acado_multBTW1( &(acadoWorkspace.evGu[ 15 ]), acadoWorkspace.W1, 3, 0 );
acado_multGxTGu( &(acadoWorkspace.evGx[ 75 ]), acadoWorkspace.W1, acadoWorkspace.W2 );
acado_multQEW2( &(acadoWorkspace.Q1[ 75 ]), &(acadoWorkspace.E[ 10 ]), acadoWorkspace.W2, acadoWorkspace.W1 );
acado_multBTW1( &(acadoWorkspace.evGu[ 10 ]), acadoWorkspace.W1, 2, 0 );
acado_multGxTGu( &(acadoWorkspace.evGx[ 50 ]), acadoWorkspace.W1, acadoWorkspace.W2 );
acado_multQEW2( &(acadoWorkspace.Q1[ 50 ]), &(acadoWorkspace.E[ 5 ]), acadoWorkspace.W2, acadoWorkspace.W1 );
acado_multBTW1( &(acadoWorkspace.evGu[ 5 ]), acadoWorkspace.W1, 1, 0 );
acado_multGxTGu( &(acadoWorkspace.evGx[ 25 ]), acadoWorkspace.W1, acadoWorkspace.W2 );
acado_multQEW2( &(acadoWorkspace.Q1[ 25 ]), acadoWorkspace.E, acadoWorkspace.W2, acadoWorkspace.W1 );
acado_multBTW1_R1( acadoWorkspace.evGu, acadoWorkspace.W1, 0 );

/* Column: 1 */
acado_moveGuE( &(acadoWorkspace.evGu[ 5 ]), &(acadoWorkspace.E[ 20 ]) );
acado_multGxGu( &(acadoWorkspace.evGx[ 50 ]), &(acadoWorkspace.E[ 20 ]), &(acadoWorkspace.E[ 25 ]) );
acado_multGxGu( &(acadoWorkspace.evGx[ 75 ]), &(acadoWorkspace.E[ 25 ]), &(acadoWorkspace.E[ 30 ]) );

acado_multGxGu( acadoWorkspace.QN1, &(acadoWorkspace.E[ 30 ]), acadoWorkspace.W1 );
acado_multBTW1( &(acadoWorkspace.evGu[ 15 ]), acadoWorkspace.W1, 3, 1 );
acado_multGxTGu( &(acadoWorkspace.evGx[ 75 ]), acadoWorkspace.W1, acadoWorkspace.W2 );
acado_multQEW2( &(acadoWorkspace.Q1[ 75 ]), &(acadoWorkspace.E[ 25 ]), acadoWorkspace.W2, acadoWorkspace.W1 );
acado_multBTW1( &(acadoWorkspace.evGu[ 10 ]), acadoWorkspace.W1, 2, 1 );
acado_multGxTGu( &(acadoWorkspace.evGx[ 50 ]), acadoWorkspace.W1, acadoWorkspace.W2 );
acado_multQEW2( &(acadoWorkspace.Q1[ 50 ]), &(acadoWorkspace.E[ 20 ]), acadoWorkspace.W2, acadoWorkspace.W1 );
acado_multBTW1_R1( &(acadoWorkspace.evGu[ 5 ]), acadoWorkspace.W1, 1 );

/* Column: 2 */
acado_moveGuE( &(acadoWorkspace.evGu[ 10 ]), &(acadoWorkspace.E[ 35 ]) );
acado_multGxGu( &(acadoWorkspace.evGx[ 75 ]), &(acadoWorkspace.E[ 35 ]), &(acadoWorkspace.E[ 40 ]) );

acado_multGxGu( acadoWorkspace.QN1, &(acadoWorkspace.E[ 40 ]), acadoWorkspace.W1 );
acado_multBTW1( &(acadoWorkspace.evGu[ 15 ]), acadoWorkspace.W1, 3, 2 );
acado_multGxTGu( &(acadoWorkspace.evGx[ 75 ]), acadoWorkspace.W1, acadoWorkspace.W2 );
acado_multQEW2( &(acadoWorkspace.Q1[ 75 ]), &(acadoWorkspace.E[ 35 ]), acadoWorkspace.W2, acadoWorkspace.W1 );
acado_multBTW1_R1( &(acadoWorkspace.evGu[ 10 ]), acadoWorkspace.W1, 2 );

/* Column: 3 */
acado_moveGuE( &(acadoWorkspace.evGu[ 15 ]), &(acadoWorkspace.E[ 45 ]) );

acado_multGxGu( acadoWorkspace.QN1, &(acadoWorkspace.E[ 45 ]), acadoWorkspace.W1 );
acado_multBTW1_R1( &(acadoWorkspace.evGu[ 15 ]), acadoWorkspace.W1, 3 );

acado_copyHTH( 0, 1 );
acado_copyHTH( 0, 2 );
acado_copyHTH( 1, 2 );
acado_copyHTH( 0, 3 );
acado_copyHTH( 1, 3 );
acado_copyHTH( 2, 3 );

acadoWorkspace.sbar[5] = acadoWorkspace.d[0];
acadoWorkspace.sbar[6] = acadoWorkspace.d[1];
acadoWorkspace.sbar[7] = acadoWorkspace.d[2];
acadoWorkspace.sbar[8] = acadoWorkspace.d[3];
acadoWorkspace.sbar[9] = acadoWorkspace.d[4];
acadoWorkspace.sbar[10] = acadoWorkspace.d[5];
acadoWorkspace.sbar[11] = acadoWorkspace.d[6];
acadoWorkspace.sbar[12] = acadoWorkspace.d[7];
acadoWorkspace.sbar[13] = acadoWorkspace.d[8];
acadoWorkspace.sbar[14] = acadoWorkspace.d[9];
acadoWorkspace.sbar[15] = acadoWorkspace.d[10];
acadoWorkspace.sbar[16] = acadoWorkspace.d[11];
acadoWorkspace.sbar[17] = acadoWorkspace.d[12];
acadoWorkspace.sbar[18] = acadoWorkspace.d[13];
acadoWorkspace.sbar[19] = acadoWorkspace.d[14];
acadoWorkspace.sbar[20] = acadoWorkspace.d[15];
acadoWorkspace.sbar[21] = acadoWorkspace.d[16];
acadoWorkspace.sbar[22] = acadoWorkspace.d[17];
acadoWorkspace.sbar[23] = acadoWorkspace.d[18];
acadoWorkspace.sbar[24] = acadoWorkspace.d[19];
acadoWorkspace.lb[0] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[0];
acadoWorkspace.lb[1] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[1];
acadoWorkspace.lb[2] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[2];
acadoWorkspace.lb[3] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[3];
acadoWorkspace.ub[0] = (real_t)1.0000000000000000e+12 - acadoVariables.u[0];
acadoWorkspace.ub[1] = (real_t)1.0000000000000000e+12 - acadoVariables.u[1];
acadoWorkspace.ub[2] = (real_t)1.0000000000000000e+12 - acadoVariables.u[2];
acadoWorkspace.ub[3] = (real_t)1.0000000000000000e+12 - acadoVariables.u[3];

acadoWorkspace.A[0] = acadoWorkspace.E[0];

acadoWorkspace.A[4] = acadoWorkspace.E[4];

acadoWorkspace.A[8] = acadoWorkspace.E[5];
acadoWorkspace.A[9] = acadoWorkspace.E[20];

acadoWorkspace.A[12] = acadoWorkspace.E[9];
acadoWorkspace.A[13] = acadoWorkspace.E[24];

acadoWorkspace.A[16] = acadoWorkspace.E[10];
acadoWorkspace.A[17] = acadoWorkspace.E[25];
acadoWorkspace.A[18] = acadoWorkspace.E[35];

acadoWorkspace.A[20] = acadoWorkspace.E[14];
acadoWorkspace.A[21] = acadoWorkspace.E[29];
acadoWorkspace.A[22] = acadoWorkspace.E[39];

acadoWorkspace.A[24] = acadoWorkspace.E[15];
acadoWorkspace.A[25] = acadoWorkspace.E[30];
acadoWorkspace.A[26] = acadoWorkspace.E[40];
acadoWorkspace.A[27] = acadoWorkspace.E[45];

acadoWorkspace.A[28] = acadoWorkspace.E[19];
acadoWorkspace.A[29] = acadoWorkspace.E[34];
acadoWorkspace.A[30] = acadoWorkspace.E[44];
acadoWorkspace.A[31] = acadoWorkspace.E[49];


}

void acado_condenseFdb(  )
{
real_t tmp;

acadoWorkspace.Dx0[0] = acadoVariables.x0[0] - acadoVariables.x[0];
acadoWorkspace.Dx0[1] = acadoVariables.x0[1] - acadoVariables.x[1];
acadoWorkspace.Dx0[2] = acadoVariables.x0[2] - acadoVariables.x[2];
acadoWorkspace.Dx0[3] = acadoVariables.x0[3] - acadoVariables.x[3];
acadoWorkspace.Dx0[4] = acadoVariables.x0[4] - acadoVariables.x[4];
acadoWorkspace.Dy[0] -= acadoVariables.y[0];
acadoWorkspace.Dy[1] -= acadoVariables.y[1];
acadoWorkspace.Dy[2] -= acadoVariables.y[2];
acadoWorkspace.Dy[3] -= acadoVariables.y[3];
acadoWorkspace.Dy[4] -= acadoVariables.y[4];
acadoWorkspace.Dy[5] -= acadoVariables.y[5];
acadoWorkspace.Dy[6] -= acadoVariables.y[6];
acadoWorkspace.Dy[7] -= acadoVariables.y[7];
acadoWorkspace.Dy[8] -= acadoVariables.y[8];
acadoWorkspace.Dy[9] -= acadoVariables.y[9];
acadoWorkspace.Dy[10] -= acadoVariables.y[10];
acadoWorkspace.Dy[11] -= acadoVariables.y[11];
acadoWorkspace.Dy[12] -= acadoVariables.y[12];
acadoWorkspace.Dy[13] -= acadoVariables.y[13];
acadoWorkspace.Dy[14] -= acadoVariables.y[14];
acadoWorkspace.Dy[15] -= acadoVariables.y[15];
acadoWorkspace.DyN[0] -= acadoVariables.yN[0];

acado_multRDy( acadoWorkspace.Dy, acadoWorkspace.g );
acado_multRDy( &(acadoWorkspace.Dy[ 4 ]), &(acadoWorkspace.g[ 1 ]) );
acado_multRDy( &(acadoWorkspace.Dy[ 8 ]), &(acadoWorkspace.g[ 2 ]) );
acado_multRDy( &(acadoWorkspace.Dy[ 12 ]), &(acadoWorkspace.g[ 3 ]) );

acado_multQDy( acadoWorkspace.Q2, acadoWorkspace.Dy, acadoWorkspace.QDy );
acado_multQDy( &(acadoWorkspace.Q2[ 20 ]), &(acadoWorkspace.Dy[ 4 ]), &(acadoWorkspace.QDy[ 5 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 40 ]), &(acadoWorkspace.Dy[ 8 ]), &(acadoWorkspace.QDy[ 10 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 60 ]), &(acadoWorkspace.Dy[ 12 ]), &(acadoWorkspace.QDy[ 15 ]) );

acadoWorkspace.QDy[20] = + acadoWorkspace.QN2[0]*acadoWorkspace.DyN[0];
acadoWorkspace.QDy[21] = + acadoWorkspace.QN2[1]*acadoWorkspace.DyN[0];
acadoWorkspace.QDy[22] = + acadoWorkspace.QN2[2]*acadoWorkspace.DyN[0];
acadoWorkspace.QDy[23] = + acadoWorkspace.QN2[3]*acadoWorkspace.DyN[0];
acadoWorkspace.QDy[24] = + acadoWorkspace.QN2[4]*acadoWorkspace.DyN[0];

acadoWorkspace.sbar[0] = acadoWorkspace.Dx0[0];
acadoWorkspace.sbar[1] = acadoWorkspace.Dx0[1];
acadoWorkspace.sbar[2] = acadoWorkspace.Dx0[2];
acadoWorkspace.sbar[3] = acadoWorkspace.Dx0[3];
acadoWorkspace.sbar[4] = acadoWorkspace.Dx0[4];
acado_macASbar( acadoWorkspace.evGx, acadoWorkspace.sbar, &(acadoWorkspace.sbar[ 5 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 25 ]), &(acadoWorkspace.sbar[ 5 ]), &(acadoWorkspace.sbar[ 10 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 50 ]), &(acadoWorkspace.sbar[ 10 ]), &(acadoWorkspace.sbar[ 15 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 75 ]), &(acadoWorkspace.sbar[ 15 ]), &(acadoWorkspace.sbar[ 20 ]) );

acadoWorkspace.w1[0] = + acadoWorkspace.QN1[0]*acadoWorkspace.sbar[20] + acadoWorkspace.QN1[1]*acadoWorkspace.sbar[21] + acadoWorkspace.QN1[2]*acadoWorkspace.sbar[22] + acadoWorkspace.QN1[3]*acadoWorkspace.sbar[23] + acadoWorkspace.QN1[4]*acadoWorkspace.sbar[24] + acadoWorkspace.QDy[20];
acadoWorkspace.w1[1] = + acadoWorkspace.QN1[5]*acadoWorkspace.sbar[20] + acadoWorkspace.QN1[6]*acadoWorkspace.sbar[21] + acadoWorkspace.QN1[7]*acadoWorkspace.sbar[22] + acadoWorkspace.QN1[8]*acadoWorkspace.sbar[23] + acadoWorkspace.QN1[9]*acadoWorkspace.sbar[24] + acadoWorkspace.QDy[21];
acadoWorkspace.w1[2] = + acadoWorkspace.QN1[10]*acadoWorkspace.sbar[20] + acadoWorkspace.QN1[11]*acadoWorkspace.sbar[21] + acadoWorkspace.QN1[12]*acadoWorkspace.sbar[22] + acadoWorkspace.QN1[13]*acadoWorkspace.sbar[23] + acadoWorkspace.QN1[14]*acadoWorkspace.sbar[24] + acadoWorkspace.QDy[22];
acadoWorkspace.w1[3] = + acadoWorkspace.QN1[15]*acadoWorkspace.sbar[20] + acadoWorkspace.QN1[16]*acadoWorkspace.sbar[21] + acadoWorkspace.QN1[17]*acadoWorkspace.sbar[22] + acadoWorkspace.QN1[18]*acadoWorkspace.sbar[23] + acadoWorkspace.QN1[19]*acadoWorkspace.sbar[24] + acadoWorkspace.QDy[23];
acadoWorkspace.w1[4] = + acadoWorkspace.QN1[20]*acadoWorkspace.sbar[20] + acadoWorkspace.QN1[21]*acadoWorkspace.sbar[21] + acadoWorkspace.QN1[22]*acadoWorkspace.sbar[22] + acadoWorkspace.QN1[23]*acadoWorkspace.sbar[23] + acadoWorkspace.QN1[24]*acadoWorkspace.sbar[24] + acadoWorkspace.QDy[24];
acado_macBTw1( &(acadoWorkspace.evGu[ 15 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 3 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 75 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 15 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 75 ]), &(acadoWorkspace.sbar[ 15 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 10 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 2 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 50 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 10 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 50 ]), &(acadoWorkspace.sbar[ 10 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 5 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 1 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 25 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 5 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 25 ]), &(acadoWorkspace.sbar[ 5 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( acadoWorkspace.evGu, acadoWorkspace.w1, acadoWorkspace.g );


tmp = acadoWorkspace.sbar[5] + acadoVariables.x[5];
acadoWorkspace.lbA[0] = (real_t)-2.0000000000000000e+00 - tmp;
acadoWorkspace.ubA[0] = (real_t)2.0000000000000000e+00 - tmp;
tmp = acadoWorkspace.sbar[9] + acadoVariables.x[9];
acadoWorkspace.lbA[1] = (real_t)-1.0000000000000000e+07 - tmp;
acadoWorkspace.ubA[1] = (real_t)1.0000000000000000e+07 - tmp;
tmp = acadoWorkspace.sbar[10] + acadoVariables.x[10];
acadoWorkspace.lbA[2] = (real_t)-2.0000000000000000e+00 - tmp;
acadoWorkspace.ubA[2] = (real_t)2.0000000000000000e+00 - tmp;
tmp = acadoWorkspace.sbar[14] + acadoVariables.x[14];
acadoWorkspace.lbA[3] = (real_t)-1.0000000000000000e+07 - tmp;
acadoWorkspace.ubA[3] = (real_t)1.0000000000000000e+07 - tmp;
tmp = acadoWorkspace.sbar[15] + acadoVariables.x[15];
acadoWorkspace.lbA[4] = (real_t)-2.0000000000000000e+00 - tmp;
acadoWorkspace.ubA[4] = (real_t)2.0000000000000000e+00 - tmp;
tmp = acadoWorkspace.sbar[19] + acadoVariables.x[19];
acadoWorkspace.lbA[5] = (real_t)-1.0000000000000000e+07 - tmp;
acadoWorkspace.ubA[5] = (real_t)1.0000000000000000e+07 - tmp;
tmp = acadoWorkspace.sbar[20] + acadoVariables.x[20];
acadoWorkspace.lbA[6] = (real_t)-2.0000000000000000e+00 - tmp;
acadoWorkspace.ubA[6] = (real_t)2.0000000000000000e+00 - tmp;
tmp = acadoWorkspace.sbar[24] + acadoVariables.x[24];
acadoWorkspace.lbA[7] = (real_t)-1.0000000000000000e+07 - tmp;
acadoWorkspace.ubA[7] = (real_t)1.0000000000000000e+07 - tmp;

}

void acado_expand(  )
{
acadoVariables.u[0] += acadoWorkspace.x[0];
acadoVariables.u[1] += acadoWorkspace.x[1];
acadoVariables.u[2] += acadoWorkspace.x[2];
acadoVariables.u[3] += acadoWorkspace.x[3];
acadoWorkspace.sbar[0] = acadoWorkspace.Dx0[0];
acadoWorkspace.sbar[1] = acadoWorkspace.Dx0[1];
acadoWorkspace.sbar[2] = acadoWorkspace.Dx0[2];
acadoWorkspace.sbar[3] = acadoWorkspace.Dx0[3];
acadoWorkspace.sbar[4] = acadoWorkspace.Dx0[4];
acadoWorkspace.sbar[5] = acadoWorkspace.d[0];
acadoWorkspace.sbar[6] = acadoWorkspace.d[1];
acadoWorkspace.sbar[7] = acadoWorkspace.d[2];
acadoWorkspace.sbar[8] = acadoWorkspace.d[3];
acadoWorkspace.sbar[9] = acadoWorkspace.d[4];
acadoWorkspace.sbar[10] = acadoWorkspace.d[5];
acadoWorkspace.sbar[11] = acadoWorkspace.d[6];
acadoWorkspace.sbar[12] = acadoWorkspace.d[7];
acadoWorkspace.sbar[13] = acadoWorkspace.d[8];
acadoWorkspace.sbar[14] = acadoWorkspace.d[9];
acadoWorkspace.sbar[15] = acadoWorkspace.d[10];
acadoWorkspace.sbar[16] = acadoWorkspace.d[11];
acadoWorkspace.sbar[17] = acadoWorkspace.d[12];
acadoWorkspace.sbar[18] = acadoWorkspace.d[13];
acadoWorkspace.sbar[19] = acadoWorkspace.d[14];
acadoWorkspace.sbar[20] = acadoWorkspace.d[15];
acadoWorkspace.sbar[21] = acadoWorkspace.d[16];
acadoWorkspace.sbar[22] = acadoWorkspace.d[17];
acadoWorkspace.sbar[23] = acadoWorkspace.d[18];
acadoWorkspace.sbar[24] = acadoWorkspace.d[19];
acado_expansionStep( acadoWorkspace.evGx, acadoWorkspace.evGu, acadoWorkspace.x, acadoWorkspace.sbar, &(acadoWorkspace.sbar[ 5 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 25 ]), &(acadoWorkspace.evGu[ 5 ]), &(acadoWorkspace.x[ 1 ]), &(acadoWorkspace.sbar[ 5 ]), &(acadoWorkspace.sbar[ 10 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 50 ]), &(acadoWorkspace.evGu[ 10 ]), &(acadoWorkspace.x[ 2 ]), &(acadoWorkspace.sbar[ 10 ]), &(acadoWorkspace.sbar[ 15 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 75 ]), &(acadoWorkspace.evGu[ 15 ]), &(acadoWorkspace.x[ 3 ]), &(acadoWorkspace.sbar[ 15 ]), &(acadoWorkspace.sbar[ 20 ]) );
acadoVariables.x[0] += acadoWorkspace.sbar[0];
acadoVariables.x[1] += acadoWorkspace.sbar[1];
acadoVariables.x[2] += acadoWorkspace.sbar[2];
acadoVariables.x[3] += acadoWorkspace.sbar[3];
acadoVariables.x[4] += acadoWorkspace.sbar[4];
acadoVariables.x[5] += acadoWorkspace.sbar[5];
acadoVariables.x[6] += acadoWorkspace.sbar[6];
acadoVariables.x[7] += acadoWorkspace.sbar[7];
acadoVariables.x[8] += acadoWorkspace.sbar[8];
acadoVariables.x[9] += acadoWorkspace.sbar[9];
acadoVariables.x[10] += acadoWorkspace.sbar[10];
acadoVariables.x[11] += acadoWorkspace.sbar[11];
acadoVariables.x[12] += acadoWorkspace.sbar[12];
acadoVariables.x[13] += acadoWorkspace.sbar[13];
acadoVariables.x[14] += acadoWorkspace.sbar[14];
acadoVariables.x[15] += acadoWorkspace.sbar[15];
acadoVariables.x[16] += acadoWorkspace.sbar[16];
acadoVariables.x[17] += acadoWorkspace.sbar[17];
acadoVariables.x[18] += acadoWorkspace.sbar[18];
acadoVariables.x[19] += acadoWorkspace.sbar[19];
acadoVariables.x[20] += acadoWorkspace.sbar[20];
acadoVariables.x[21] += acadoWorkspace.sbar[21];
acadoVariables.x[22] += acadoWorkspace.sbar[22];
acadoVariables.x[23] += acadoWorkspace.sbar[23];
acadoVariables.x[24] += acadoWorkspace.sbar[24];
}

int acado_preparationStep(  )
{
int ret;

ret = acado_modelSimulation();
acado_evaluateObjective(  );
acado_condensePrep(  );
return ret;
}

int acado_feedbackStep(  )
{
int tmp;

acado_condenseFdb(  );

tmp = acado_solve( );

acado_expand(  );
return tmp;
}

int acado_initializeSolver(  )
{
int ret;

/* This is a function which must be called once before any other function call! */


ret = 0;

memset(&acadoWorkspace, 0, sizeof( acadoWorkspace ));
return ret;
}

void acado_initializeNodesByForwardSimulation(  )
{
int index;
for (index = 0; index < 4; ++index)
{
acadoWorkspace.state[0] = acadoVariables.x[index * 5];
acadoWorkspace.state[1] = acadoVariables.x[index * 5 + 1];
acadoWorkspace.state[2] = acadoVariables.x[index * 5 + 2];
acadoWorkspace.state[3] = acadoVariables.x[index * 5 + 3];
acadoWorkspace.state[4] = acadoVariables.x[index * 5 + 4];
acadoWorkspace.state[35] = acadoVariables.u[index];

acado_integrate(acadoWorkspace.state, index == 0);

acadoVariables.x[index * 5 + 5] = acadoWorkspace.state[0];
acadoVariables.x[index * 5 + 6] = acadoWorkspace.state[1];
acadoVariables.x[index * 5 + 7] = acadoWorkspace.state[2];
acadoVariables.x[index * 5 + 8] = acadoWorkspace.state[3];
acadoVariables.x[index * 5 + 9] = acadoWorkspace.state[4];
}
}

void acado_shiftStates( int strategy, real_t* const xEnd, real_t* const uEnd )
{
int index;
for (index = 0; index < 4; ++index)
{
acadoVariables.x[index * 5] = acadoVariables.x[index * 5 + 5];
acadoVariables.x[index * 5 + 1] = acadoVariables.x[index * 5 + 6];
acadoVariables.x[index * 5 + 2] = acadoVariables.x[index * 5 + 7];
acadoVariables.x[index * 5 + 3] = acadoVariables.x[index * 5 + 8];
acadoVariables.x[index * 5 + 4] = acadoVariables.x[index * 5 + 9];
}

if (strategy == 1 && xEnd != 0)
{
acadoVariables.x[20] = xEnd[0];
acadoVariables.x[21] = xEnd[1];
acadoVariables.x[22] = xEnd[2];
acadoVariables.x[23] = xEnd[3];
acadoVariables.x[24] = xEnd[4];
}
else if (strategy == 2) 
{
acadoWorkspace.state[0] = acadoVariables.x[20];
acadoWorkspace.state[1] = acadoVariables.x[21];
acadoWorkspace.state[2] = acadoVariables.x[22];
acadoWorkspace.state[3] = acadoVariables.x[23];
acadoWorkspace.state[4] = acadoVariables.x[24];
if (uEnd != 0)
{
acadoWorkspace.state[35] = uEnd[0];
}
else
{
acadoWorkspace.state[35] = acadoVariables.u[3];
}

acado_integrate(acadoWorkspace.state, 1);

acadoVariables.x[20] = acadoWorkspace.state[0];
acadoVariables.x[21] = acadoWorkspace.state[1];
acadoVariables.x[22] = acadoWorkspace.state[2];
acadoVariables.x[23] = acadoWorkspace.state[3];
acadoVariables.x[24] = acadoWorkspace.state[4];
}
}

void acado_shiftControls( real_t* const uEnd )
{
int index;
for (index = 0; index < 3; ++index)
{
acadoVariables.u[index] = acadoVariables.u[index + 1];
}

if (uEnd != 0)
{
acadoVariables.u[3] = uEnd[0];
}
}

real_t acado_getKKT(  )
{
real_t kkt;

int index;
real_t prd;

kkt = + acadoWorkspace.g[0]*acadoWorkspace.x[0] + acadoWorkspace.g[1]*acadoWorkspace.x[1] + acadoWorkspace.g[2]*acadoWorkspace.x[2] + acadoWorkspace.g[3]*acadoWorkspace.x[3];
kkt = fabs( kkt );
for (index = 0; index < 4; ++index)
{
prd = acadoWorkspace.y[index];
if (prd > 1e-12)
kkt += fabs(acadoWorkspace.lb[index] * prd);
else if (prd < -1e-12)
kkt += fabs(acadoWorkspace.ub[index] * prd);
}
for (index = 0; index < 8; ++index)
{
prd = acadoWorkspace.y[index + 4];
if (prd > 1e-12)
kkt += fabs(acadoWorkspace.lbA[index] * prd);
else if (prd < -1e-12)
kkt += fabs(acadoWorkspace.ubA[index] * prd);
}
return kkt;
}

real_t acado_getObjective(  )
{
real_t objVal;

int lRun1;
/** Row vector of size: 4 */
real_t tmpDy[ 4 ];

/** Column vector of size: 1 */
real_t tmpDyN[ 1 ];

for (lRun1 = 0; lRun1 < 4; ++lRun1)
{
acadoWorkspace.objValueIn[0] = acadoVariables.x[lRun1 * 5];
acadoWorkspace.objValueIn[1] = acadoVariables.x[lRun1 * 5 + 1];
acadoWorkspace.objValueIn[2] = acadoVariables.x[lRun1 * 5 + 2];
acadoWorkspace.objValueIn[3] = acadoVariables.x[lRun1 * 5 + 3];
acadoWorkspace.objValueIn[4] = acadoVariables.x[lRun1 * 5 + 4];
acadoWorkspace.objValueIn[5] = acadoVariables.u[lRun1];

acado_evaluateLSQ( acadoWorkspace.objValueIn, acadoWorkspace.objValueOut );
acadoWorkspace.Dy[lRun1 * 4] = acadoWorkspace.objValueOut[0] - acadoVariables.y[lRun1 * 4];
acadoWorkspace.Dy[lRun1 * 4 + 1] = acadoWorkspace.objValueOut[1] - acadoVariables.y[lRun1 * 4 + 1];
acadoWorkspace.Dy[lRun1 * 4 + 2] = acadoWorkspace.objValueOut[2] - acadoVariables.y[lRun1 * 4 + 2];
acadoWorkspace.Dy[lRun1 * 4 + 3] = acadoWorkspace.objValueOut[3] - acadoVariables.y[lRun1 * 4 + 3];
}
acadoWorkspace.objValueIn[0] = acadoVariables.x[20];
acadoWorkspace.objValueIn[1] = acadoVariables.x[21];
acadoWorkspace.objValueIn[2] = acadoVariables.x[22];
acadoWorkspace.objValueIn[3] = acadoVariables.x[23];
acadoWorkspace.objValueIn[4] = acadoVariables.x[24];
acado_evaluateLSQEndTerm( acadoWorkspace.objValueIn, acadoWorkspace.objValueOut );
acadoWorkspace.DyN[0] = acadoWorkspace.objValueOut[0] - acadoVariables.yN[0];
objVal = 0.0000000000000000e+00;
for (lRun1 = 0; lRun1 < 4; ++lRun1)
{
tmpDy[0] = + acadoWorkspace.Dy[lRun1 * 4]*acadoVariables.W[0];
tmpDy[1] = + acadoWorkspace.Dy[lRun1 * 4 + 1]*acadoVariables.W[5];
tmpDy[2] = + acadoWorkspace.Dy[lRun1 * 4 + 2]*acadoVariables.W[10];
tmpDy[3] = + acadoWorkspace.Dy[lRun1 * 4 + 3]*acadoVariables.W[15];
objVal += + acadoWorkspace.Dy[lRun1 * 4]*tmpDy[0] + acadoWorkspace.Dy[lRun1 * 4 + 1]*tmpDy[1] + acadoWorkspace.Dy[lRun1 * 4 + 2]*tmpDy[2] + acadoWorkspace.Dy[lRun1 * 4 + 3]*tmpDy[3];
}

tmpDyN[0] = + acadoWorkspace.DyN[0]*acadoVariables.WN[0];
objVal += + acadoWorkspace.DyN[0]*tmpDyN[0];

objVal *= 0.5;
return objVal;
}

