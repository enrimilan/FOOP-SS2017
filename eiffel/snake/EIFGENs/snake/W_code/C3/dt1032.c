/*
 * Code for class DT_DATE_TIME_DURATION
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F1032_7955(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void F1032_7956(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void F1032_7957(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void F1032_7958(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void F1032_7959(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F1032_7960(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F1032_7961(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void F1032_7962(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F1032_7963(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1032_7964(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1032_7965(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1032_7966(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1032_7967(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1032_7968(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1032_7969(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F1032_7970(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F1032_7971(EIF_REFERENCE);
extern void F1032_7972(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F1032_7973(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1032_7974(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1032_7975(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1032_7976(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1032_7977(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1032_7978(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1032_7979(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1032_7980(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1032_7981(EIF_REFERENCE);
extern void EIF_Minit1032(void);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {DT_DATE_TIME_DURATION}.make */
void F1032_7955 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x, EIF_TYPED_VALUE arg4x, EIF_TYPED_VALUE arg5x, EIF_TYPED_VALUE arg6x)
{
	GTCX
	char *l_feature_name = "make";
	RTEX;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_i4
#define arg3 arg3x.it_i4
#define arg4 arg4x.it_i4
#define arg5 arg5x.it_i4
#define arg6 arg6x.it_i4
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg6x.type & SK_HEAD) == SK_REF) arg6x.it_i4 = * (EIF_INTEGER_32 *) arg6x.it_r;
	if ((arg5x.type & SK_HEAD) == SK_REF) arg5x.it_i4 = * (EIF_INTEGER_32 *) arg5x.it_r;
	if ((arg4x.type & SK_HEAD) == SK_REF) arg4x.it_i4 = * (EIF_INTEGER_32 *) arg4x.it_r;
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_i4 = * (EIF_INTEGER_32 *) arg3x.it_r;
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU(SK_INT32,&arg3);
	RTLU(SK_INT32,&arg4);
	RTLU(SK_INT32,&arg5);
	RTLU(SK_INT32,&arg6);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 6, 14062);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14062);
	RTIV(Current, RTAL);
	RTHOOK(1);
	ui4_1 = arg1;
	ui4_2 = arg2;
	ui4_3 = arg3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5616, dtype))(Current, ui4_1x, ui4_2x, ui4_3x);
	RTHOOK(2);
	ui4_1 = arg4;
	ui4_2 = arg5;
	ui4_3 = arg6;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5650, dtype))(Current, ui4_1x, ui4_2x, ui4_3x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
		RTCT("year_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg1)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(4);
		RTCT("month_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(5);
		RTCT("day_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg3)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(6);
		RTCT("hour_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg4)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(7);
		RTCT("minute_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg5)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(8);
		RTCT("second_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg6)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(9);
		RTCT("millisecond_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(10);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(8);
	RTEE;
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef arg6
#undef arg5
#undef arg4
#undef arg3
#undef arg2
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.make_precise */
void F1032_7956 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x, EIF_TYPED_VALUE arg4x, EIF_TYPED_VALUE arg5x, EIF_TYPED_VALUE arg6x, EIF_TYPED_VALUE arg7x)
{
	GTCX
	char *l_feature_name = "make_precise";
	RTEX;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_i4
#define arg3 arg3x.it_i4
#define arg4 arg4x.it_i4
#define arg5 arg5x.it_i4
#define arg6 arg6x.it_i4
#define arg7 arg7x.it_i4
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE ui4_4x = {{0}, SK_INT32};
#define ui4_4 ui4_4x.it_i4
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg7x.type & SK_HEAD) == SK_REF) arg7x.it_i4 = * (EIF_INTEGER_32 *) arg7x.it_r;
	if ((arg6x.type & SK_HEAD) == SK_REF) arg6x.it_i4 = * (EIF_INTEGER_32 *) arg6x.it_r;
	if ((arg5x.type & SK_HEAD) == SK_REF) arg5x.it_i4 = * (EIF_INTEGER_32 *) arg5x.it_r;
	if ((arg4x.type & SK_HEAD) == SK_REF) arg4x.it_i4 = * (EIF_INTEGER_32 *) arg4x.it_r;
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_i4 = * (EIF_INTEGER_32 *) arg3x.it_r;
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU(SK_INT32,&arg3);
	RTLU(SK_INT32,&arg4);
	RTLU(SK_INT32,&arg5);
	RTLU(SK_INT32,&arg6);
	RTLU(SK_INT32,&arg7);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 7, 14063);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14063);
	RTIV(Current, RTAL);
	RTHOOK(1);
	ui4_1 = arg1;
	ui4_2 = arg2;
	ui4_3 = arg3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5616, dtype))(Current, ui4_1x, ui4_2x, ui4_3x);
	RTHOOK(2);
	ui4_1 = arg4;
	ui4_2 = arg5;
	ui4_3 = arg6;
	ui4_4 = arg7;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5651, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
		RTCT("year_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg1)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(4);
		RTCT("month_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(5);
		RTCT("day_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg3)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(6);
		RTCT("hour_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg4)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(7);
		RTCT("minute_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg5)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(8);
		RTCT("second_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg6)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(9);
		RTCT("millisecond_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg7)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(10);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(9);
	RTEE;
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef ui4_4
#undef arg7
#undef arg6
#undef arg5
#undef arg4
#undef arg3
#undef arg2
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.make_definite */
void F1032_7957 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x, EIF_TYPED_VALUE arg4x)
{
	GTCX
	char *l_feature_name = "make_definite";
	RTEX;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_i4
#define arg3 arg3x.it_i4
#define arg4 arg4x.it_i4
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg4x.type & SK_HEAD) == SK_REF) arg4x.it_i4 = * (EIF_INTEGER_32 *) arg4x.it_r;
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_i4 = * (EIF_INTEGER_32 *) arg3x.it_r;
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU(SK_INT32,&arg3);
	RTLU(SK_INT32,&arg4);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 4, 14064);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14064);
	RTIV(Current, RTAL);
	RTHOOK(1);
	ui4_1 = arg1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5617, dtype))(Current, ui4_1x);
	RTHOOK(2);
	ui4_1 = arg2;
	ui4_2 = arg3;
	ui4_3 = arg4;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5650, dtype))(Current, ui4_1x, ui4_2x, ui4_3x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
		RTCT("is_definite", EX_POST);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5619, dtype))(Current)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(4);
		RTCT("day_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg1)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(5);
		RTCT("hour_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(6);
		RTCT("minute_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg3)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(7);
		RTCT("second_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg4)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(8);
		RTCT("millisecond_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(6);
	RTEE;
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef arg4
#undef arg3
#undef arg2
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.make_precise_definite */
void F1032_7958 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x, EIF_TYPED_VALUE arg4x, EIF_TYPED_VALUE arg5x)
{
	GTCX
	char *l_feature_name = "make_precise_definite";
	RTEX;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_i4
#define arg3 arg3x.it_i4
#define arg4 arg4x.it_i4
#define arg5 arg5x.it_i4
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE ui4_4x = {{0}, SK_INT32};
#define ui4_4 ui4_4x.it_i4
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg5x.type & SK_HEAD) == SK_REF) arg5x.it_i4 = * (EIF_INTEGER_32 *) arg5x.it_r;
	if ((arg4x.type & SK_HEAD) == SK_REF) arg4x.it_i4 = * (EIF_INTEGER_32 *) arg4x.it_r;
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_i4 = * (EIF_INTEGER_32 *) arg3x.it_r;
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU(SK_INT32,&arg3);
	RTLU(SK_INT32,&arg4);
	RTLU(SK_INT32,&arg5);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 5, 14065);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14065);
	RTIV(Current, RTAL);
	RTHOOK(1);
	ui4_1 = arg1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5617, dtype))(Current, ui4_1x);
	RTHOOK(2);
	ui4_1 = arg2;
	ui4_2 = arg3;
	ui4_3 = arg4;
	ui4_4 = arg5;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5651, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
		RTCT("is_definite", EX_POST);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5619, dtype))(Current)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(4);
		RTCT("day_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg1)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(5);
		RTCT("hour_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(6);
		RTCT("minute_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg3)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(7);
		RTCT("second_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg4)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(8);
		RTCT("millisecond_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == arg5)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(7);
	RTEE;
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef ui4_4
#undef arg5
#undef arg4
#undef arg3
#undef arg2
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.make_canonical_definite */
void F1032_7959 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "make_canonical_definite";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
#define arg1 arg1x.it_i4
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_BOOLEAN tb1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	
	RTEAA(l_feature_name, 1031, Current, 2, 1, 14066);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14066);
	RTIV(Current, RTAL);
	RTHOOK(1);
	if ((EIF_BOOLEAN) (arg1 < ((EIF_INTEGER_32) 0L))) {
		RTHOOK(2);
		RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
		loc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5494, dtype))(Current)).it_i4);
		loc1 = (EIF_INTEGER_32) (EIF_INTEGER_32) -((EIF_INTEGER_32) ((EIF_INTEGER_32) -arg1 / loc1));
		RTHOOK(3);
		RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
		loc2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5494, dtype))(Current)).it_i4);
		loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) -((EIF_INTEGER_32) ((EIF_INTEGER_32) -arg1 % loc2));
	} else {
		RTHOOK(4);
		RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
		loc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5494, dtype))(Current)).it_i4);
		loc1 = (EIF_INTEGER_32) (EIF_INTEGER_32) (arg1 / loc1);
		RTHOOK(5);
		RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
		loc2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5494, dtype))(Current)).it_i4);
		loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) (arg1 % loc2);
	}
	RTHOOK(6);
	ui4_1 = loc1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5617, dtype))(Current, ui4_1x);
	RTHOOK(7);
	ui4_1 = loc2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5652, dtype))(Current, ui4_1x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(8);
		RTCT("is_definite", EX_POST);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5619, dtype))(Current)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(9);
		RTCT("canonical_time", EX_POST);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5711, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(9,1);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5654, "is_canonical", tr1))(tr1)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(10);
		RTCT("second_count_set", EX_POST);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5655, dtype))(Current)).it_i4);
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5494, dtype))(Current)).it_i4);
		if ((EIF_BOOLEAN)(arg1 == (EIF_INTEGER_32) (ti4_1 + (EIF_INTEGER_32) (ti4_2 * ti4_3)))) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(11);
		RTCT("millisecond_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(12);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(5);
	RTEE;
#undef up1
#undef ui4_1
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.make_precise_canonical_definite */
void F1032_7960 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "make_precise_canonical_definite";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
#define arg1 arg1x.it_i4
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_BOOLEAN tb1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	
	RTEAA(l_feature_name, 1031, Current, 2, 1, 14067);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14067);
	RTIV(Current, RTAL);
	RTHOOK(1);
	if ((EIF_BOOLEAN) (arg1 < ((EIF_INTEGER_32) 0L))) {
		RTHOOK(2);
		RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
		loc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc1 = (EIF_INTEGER_32) (EIF_INTEGER_32) -((EIF_INTEGER_32) ((EIF_INTEGER_32) -arg1 / loc1));
		RTHOOK(3);
		RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
		loc2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) -((EIF_INTEGER_32) ((EIF_INTEGER_32) -arg1 % loc2));
	} else {
		RTHOOK(4);
		RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
		loc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc1 = (EIF_INTEGER_32) (EIF_INTEGER_32) (arg1 / loc1);
		RTHOOK(5);
		RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
		loc2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) (arg1 % loc2);
	}
	RTHOOK(6);
	ui4_1 = loc1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5617, dtype))(Current, ui4_1x);
	RTHOOK(7);
	ui4_1 = loc2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5653, dtype))(Current, ui4_1x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(8);
		RTCT("is_definite", EX_POST);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5619, dtype))(Current)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(9);
		RTCT("canonical_time", EX_POST);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5711, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(9,1);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5654, "is_canonical", tr1))(tr1)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(10);
		RTCT("millisecond_count_set", EX_POST);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		if ((EIF_BOOLEAN)(arg1 == (EIF_INTEGER_32) (ti4_1 + (EIF_INTEGER_32) (ti4_2 * ti4_3)))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(11);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(5);
	RTEE;
#undef up1
#undef ui4_1
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.make_from_date_time_duration */
void F1032_7961 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "make_from_date_time_duration";
	RTEX;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(3);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,Current);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 2, 14068);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14068);
	RTCC(arg1, 1031, l_feature_name, 1, eif_new_type(1025, 0x01), 0x01);
	RTCC(arg2, 1031, l_feature_name, 2, eif_new_type(1027, 0x01), 0x01);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("a_date_duration_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTHOOK(2);
		RTCT("a_time_duration_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg2 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 5638, 0x10000000, 1); /* year */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5638, "year", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(4);
	RTDBGAA(Current, dtype, 5637, 0x10000000, 1); /* month */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5637, "month", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(5);
	RTDBGAA(Current, dtype, 5636, 0x10000000, 1); /* day */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(6);
	RTDBGAA(Current, dtype, 5676, 0x10000000, 1); /* hour */
	ti4_1 = *(EIF_INTEGER_32 *)(arg2 + RTVA(5676, "hour", arg2));
	*(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(7);
	RTDBGAA(Current, dtype, 5675, 0x10000000, 1); /* minute */
	ti4_1 = *(EIF_INTEGER_32 *)(arg2 + RTVA(5675, "minute", arg2));
	*(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(8);
	RTDBGAA(Current, dtype, 5674, 0x10000000, 1); /* second */
	ti4_1 = *(EIF_INTEGER_32 *)(arg2 + RTVA(5674, "second", arg2));
	*(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(9);
	RTDBGAA(Current, dtype, 5673, 0x10000000, 1); /* millisecond */
	ti4_1 = *(EIF_INTEGER_32 *)(arg2 + RTVA(5673, "millisecond", arg2));
	*(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype)) = (EIF_INTEGER_32) ti4_1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(10);
		RTCT("year_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5638, "year", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(11);
		RTCT("month_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5637, "month", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(12);
		RTCT("day_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(13);
		RTCT("hour_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg2 + RTVA(5676, "hour", arg2));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(14);
		RTCT("minute_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg2 + RTVA(5675, "minute", arg2));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(15);
		RTCT("second_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg2 + RTVA(5674, "second", arg2));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(16);
		RTCT("millisecond_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg2 + RTVA(5673, "millisecond", arg2));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(17);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
#undef arg2
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.make_from_date_duration */
void F1032_7962 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "make_from_date_duration";
	RTEX;
#define arg1 arg1x.it_r
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(2);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 1, 14069);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14069);
	RTCC(arg1, 1031, l_feature_name, 1, eif_new_type(1025, 0x01), 0x01);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("a_date_duration_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 5638, 0x10000000, 1); /* year */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5638, "year", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 5637, 0x10000000, 1); /* month */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5637, "month", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(4);
	RTDBGAA(Current, dtype, 5636, 0x10000000, 1); /* day */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(5);
	RTDBGAA(Current, dtype, 5676, 0x10000000, 1); /* hour */
	*(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	RTHOOK(6);
	RTDBGAA(Current, dtype, 5675, 0x10000000, 1); /* minute */
	*(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	RTHOOK(7);
	RTDBGAA(Current, dtype, 5674, 0x10000000, 1); /* second */
	*(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	RTHOOK(8);
	RTDBGAA(Current, dtype, 5673, 0x10000000, 1); /* millisecond */
	*(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	if (RTAL & CK_ENSURE) {
		RTHOOK(9);
		RTCT("year_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5638, "year", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(10);
		RTCT("month_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5637, "month", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(11);
		RTCT("day_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(12);
		RTCT("hour_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L))) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(13);
		RTCT("minute_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L))) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(14);
		RTCT("second_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L))) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(15);
		RTCT("millisecond_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(16);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.make_canonical_from_dates */
void F1032_7963 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "make_canonical_from_dates";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc4 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc5 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc6 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc7 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc8 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc9 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc10 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc11 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc12 = (EIF_INTEGER_32) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE ui4_4x = {{0}, SK_INT32};
#define ui4_4 ui4_4x.it_i4
	EIF_TYPED_VALUE ui4_5x = {{0}, SK_INT32};
#define ui4_5 ui4_5x.it_i4
	EIF_TYPED_VALUE ui4_6x = {{0}, SK_INT32};
#define ui4_6 ui4_6x.it_i4
	EIF_TYPED_VALUE ui4_7x = {{0}, SK_INT32};
#define ui4_7 ui4_7x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,ur1);
	RTLR(3,Current);
	RTLR(4,tr1);
	RTLIU(5);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_INT32, &loc3);
	RTLU(SK_INT32, &loc4);
	RTLU(SK_INT32, &loc5);
	RTLU(SK_INT32, &loc6);
	RTLU(SK_INT32, &loc7);
	RTLU(SK_INT32, &loc8);
	RTLU(SK_INT32, &loc9);
	RTLU(SK_INT32, &loc10);
	RTLU(SK_INT32, &loc11);
	RTLU(SK_INT32, &loc12);
	
	RTEAA(l_feature_name, 1031, Current, 12, 2, 14070);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14070);
	RTCC(arg1, 1031, l_feature_name, 1, RTWCT(5571, dtype, Dftype(Current)), 0x00);
	RTCC(arg2, 1031, l_feature_name, 2, RTWCT(5571, dtype, Dftype(Current)), 0x00);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("date_from_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTHOOK(2);
		RTCT("date_to_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg2 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(3);
	RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5580, "year", arg2))(arg2)).it_i4);
	ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5580, "year", arg1))(arg1)).it_i4);
	loc1 = (EIF_INTEGER_32) (EIF_INTEGER_32) (ti4_1 - ti4_2);
	RTHOOK(4);
	RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5581, "month", arg2))(arg2)).it_i4);
	ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5581, "month", arg1))(arg1)).it_i4);
	loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) (ti4_1 - ti4_2);
	RTHOOK(5);
	RTDBGAL(Current, 10, 0x10000000, 1, 0); /* loc10 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5582, "day", arg2))(arg2)).it_i4);
	loc10 = (EIF_INTEGER_32) ti4_1;
	RTHOOK(6);
	RTDBGAL(Current, 9, 0x10000000, 1, 0); /* loc9 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5582, "day", arg1))(arg1)).it_i4);
	loc9 = (EIF_INTEGER_32) ti4_1;
	RTHOOK(7);
	RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
	loc3 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc10 - loc9);
	RTHOOK(8);
	RTDBGAL(Current, 4, 0x10000000, 1, 0); /* loc4 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5683, "millisecond_count", arg2))(arg2)).it_i4);
	ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5683, "millisecond_count", arg1))(arg1)).it_i4);
	loc4 = (EIF_INTEGER_32) (EIF_INTEGER_32) (ti4_1 - ti4_2);
	RTHOOK(9);
	ur1 = RTCCL(arg2);
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(1342, "is_less", arg1))(arg1, ur1x)).it_b);
	if (tb1) {
		RTHOOK(10);
		if ((EIF_BOOLEAN) (loc4 < ((EIF_INTEGER_32) 0L))) {
			RTHOOK(11);
			RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
			loc3--;
			RTHOOK(12);
			RTDBGAL(Current, 4, 0x10000000, 1, 0); /* loc4 */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
			loc4 += ti4_1;
		}
		RTHOOK(13);
		RTDBGAL(Current, 8, 0x10000000, 1, 0); /* loc8 */
		loc8 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc4 % ((EIF_INTEGER_32) 1000L));
		RTHOOK(14);
		RTDBGAL(Current, 4, 0x10000000, 1, 0); /* loc4 */
		loc4 /= ((EIF_INTEGER_32) 1000L);
		RTHOOK(15);
		RTDBGAL(Current, 7, 0x10000000, 1, 0); /* loc7 */
		loc7 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
		loc7 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc4 % loc7);
		RTHOOK(16);
		RTDBGAL(Current, 4, 0x10000000, 1, 0); /* loc4 */
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
		loc4 /= ti4_1;
		RTHOOK(17);
		RTDBGAL(Current, 6, 0x10000000, 1, 0); /* loc6 */
		loc6 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
		loc6 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc4 % loc6);
		RTHOOK(18);
		RTDBGAL(Current, 5, 0x10000000, 1, 0); /* loc5 */
		loc5 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
		loc5 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc4 / loc5);
		RTHOOK(19);
		if ((EIF_BOOLEAN) (loc3 < ((EIF_INTEGER_32) 0L))) {
			RTHOOK(20);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			loc2--;
			RTHOOK(21);
			RTDBGAL(Current, 11, 0x10000000, 1, 0); /* loc11 */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5596, "days_in_previous_month", arg2))(arg2)).it_i4);
			loc11 = (EIF_INTEGER_32) ti4_1;
			RTHOOK(22);
			if ((EIF_BOOLEAN) (loc11 < loc9)) {
				RTHOOK(23);
				RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
				loc3 += loc9;
			} else {
				RTHOOK(24);
				RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
				loc3 += loc11;
			}
		}
		RTHOOK(25);
		if ((EIF_BOOLEAN) (loc2 < ((EIF_INTEGER_32) 0L))) {
			RTHOOK(26);
			RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
			loc1--;
			RTHOOK(27);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5466, dtype))(Current)).it_i4);
			loc2 += ti4_1;
		}
	} else {
		RTHOOK(28);
		if ((EIF_BOOLEAN) (loc4 > ((EIF_INTEGER_32) 0L))) {
			RTHOOK(29);
			RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
			loc3++;
			RTHOOK(30);
			RTDBGAL(Current, 4, 0x10000000, 1, 0); /* loc4 */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
			loc4 -= ti4_1;
		}
		RTHOOK(31);
		RTDBGAL(Current, 4, 0x10000000, 1, 0); /* loc4 */
		loc4 = (EIF_INTEGER_32) (EIF_INTEGER_32) -loc4;
		RTHOOK(32);
		RTDBGAL(Current, 8, 0x10000000, 1, 0); /* loc8 */
		loc8 = (EIF_INTEGER_32) (EIF_INTEGER_32) -(EIF_INTEGER_32) (loc4 % ((EIF_INTEGER_32) 1000L));
		RTHOOK(33);
		RTDBGAL(Current, 4, 0x10000000, 1, 0); /* loc4 */
		loc4 /= ((EIF_INTEGER_32) 1000L);
		RTHOOK(34);
		RTDBGAL(Current, 7, 0x10000000, 1, 0); /* loc7 */
		loc7 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
		loc7 = (EIF_INTEGER_32) (EIF_INTEGER_32) -(EIF_INTEGER_32) (loc4 % loc7);
		RTHOOK(35);
		RTDBGAL(Current, 4, 0x10000000, 1, 0); /* loc4 */
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
		loc4 /= ti4_1;
		RTHOOK(36);
		RTDBGAL(Current, 6, 0x10000000, 1, 0); /* loc6 */
		loc6 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
		loc6 = (EIF_INTEGER_32) (EIF_INTEGER_32) -(EIF_INTEGER_32) (loc4 % loc6);
		RTHOOK(37);
		RTDBGAL(Current, 5, 0x10000000, 1, 0); /* loc5 */
		loc5 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
		loc5 = (EIF_INTEGER_32) (EIF_INTEGER_32) -(EIF_INTEGER_32) (loc4 / loc5);
		RTHOOK(38);
		RTDBGAL(Current, 12, 0x10000000, 1, 0); /* loc12 */
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5595, "days_in_current_month", arg2))(arg2)).it_i4);
		loc12 = (EIF_INTEGER_32) ti4_1;
		RTHOOK(39);
		if ((EIF_BOOLEAN) (loc3 > ((EIF_INTEGER_32) 0L))) {
			RTHOOK(40);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			loc2++;
			RTHOOK(41);
			RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
			loc3 -= loc12;
		} else {
			RTHOOK(42);
			if ((EIF_BOOLEAN) (loc12 < loc9)) {
				RTHOOK(43);
				RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
				loc3 = (EIF_INTEGER_32) (EIF_INTEGER_32) ((EIF_INTEGER_32) (loc3 + loc9) - loc12);
			}
		}
		RTHOOK(44);
		if ((EIF_BOOLEAN) (loc2 > ((EIF_INTEGER_32) 0L))) {
			RTHOOK(45);
			RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
			loc1++;
			RTHOOK(46);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5466, dtype))(Current)).it_i4);
			loc2 -= ti4_1;
		}
	}
	RTHOOK(47);
	ui4_1 = loc1;
	ui4_2 = loc2;
	ui4_3 = loc3;
	ui4_4 = loc5;
	ui4_5 = loc6;
	ui4_6 = loc7;
	ui4_7 = loc8;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5721, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x, ui4_7x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(48);
		RTCT("canonical_duration", EX_POST);
		ur1 = RTCCL(arg1);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5620, dtype))(Current, ur1x)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(49);
		RTCT("definition", EX_POST);
		ur1 = RTCCL(Current);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(arg2);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(11, "is_equal", tr1))(tr1, ur1x)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(50);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(16);
	RTEE;
#undef up1
#undef ur1
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef ui4_4
#undef ui4_5
#undef ui4_6
#undef ui4_7
#undef arg2
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.is_canonical */
EIF_TYPED_VALUE F1032_7964 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "is_canonical";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_INTEGER_32 ti4_5;
	EIF_INTEGER_32 ti4_6;
	EIF_INTEGER_32 ti4_7;
	EIF_INTEGER_32 ti4_8;
	EIF_INTEGER_32 ti4_9;
	EIF_INTEGER_32 ti4_10;
	EIF_INTEGER_32 ti4_11;
	EIF_INTEGER_32 ti4_12;
	EIF_INTEGER_32 ti4_13;
	EIF_INTEGER_32 ti4_14;
	EIF_INTEGER_32 ti4_15;
	EIF_INTEGER_32 ti4_16;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_BOOLEAN tb3;
	EIF_BOOLEAN tb4;
	EIF_BOOLEAN tb5;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,loc1);
	RTLR(2,Current);
	RTLR(3,ur1);
	RTLR(4,tr1);
	RTLIU(5);
	RTLU (SK_BOOL, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 1031, Current, 1, 1, 14071);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14071);
	RTCC(arg1, 1031, l_feature_name, 1, RTWCT(5571, dtype, Dftype(Current)), 0x00);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("a_date_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(Current, 1, 0xF8000406, 0, 0); /* loc1 */
	loc1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5731, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTHOOK(3);
	ur1 = RTCCL(arg1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5599, "set_date", loc1))(loc1, ur1x);
	RTHOOK(4);
	ur1 = RTCCL(arg1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5687, "set_time", loc1))(loc1, ur1x);
	RTHOOK(5);
	ur1 = RTCCL(Current);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5579, "add_duration", loc1))(loc1, ur1x);
	RTHOOK(6);
	ur1 = RTCCL(loc1);
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(1343, "is_less_equal", arg1))(arg1, ur1x)).it_b);
	if (tb1) {
		RTHOOK(7);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5497, dtype))(Current)).it_i4);
		ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		ti4_6 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
		ti4_7 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		ti4_8 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		ti4_9 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
		ti4_10 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		ti4_11 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		ti4_12 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		ti4_13 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		ti4_14 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		ti4_15 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5466, dtype))(Current)).it_i4);
		ti4_16 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 < ti4_3)) && (EIF_BOOLEAN) (ti4_4 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_5 < ti4_6)) && (EIF_BOOLEAN) (ti4_7 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_8 < ti4_9)) && (EIF_BOOLEAN) (ti4_10 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_11 < ((EIF_INTEGER_32) 1000L))) && (EIF_BOOLEAN) (ti4_12 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_13 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_14 < ti4_15)) && (EIF_BOOLEAN) (ti4_16 >= ((EIF_INTEGER_32) 0L)))) {
			RTHOOK(8);
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
			ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5582, "day", loc1))(loc1)).it_i4);
			if ((EIF_BOOLEAN) (ti4_1 >= ti4_2)) {
				RTHOOK(9);
				RTDBGAL(Current, 0, 0x04000000, 1,0); /* Result */
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
				ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5596, "days_in_previous_month", loc1))(loc1)).it_i4);
				Result = (EIF_BOOLEAN) (EIF_BOOLEAN) (ti4_1 < ti4_2);
			} else {
				RTHOOK(10);
				RTDBGAL(Current, 0, 0x04000000, 1,0); /* Result */
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
				ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5595, "days_in_current_month", loc1))(loc1)).it_i4);
				Result = (EIF_BOOLEAN) (EIF_BOOLEAN) (ti4_1 < ti4_2);
			}
		}
	} else {
		RTHOOK(11);
		RTDBGAL(Current, 0, 0x04000000, 1,0); /* Result */
		tb1 = '\0';
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5497, dtype))(Current)).it_i4);
		ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		ti4_6 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
		ti4_7 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		ti4_8 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		ti4_9 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
		ti4_10 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		ti4_11 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		ti4_12 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		ti4_13 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		ti4_14 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		ti4_15 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5466, dtype))(Current)).it_i4);
		ti4_16 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 <= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 > (EIF_INTEGER_32) -ti4_3)) && (EIF_BOOLEAN) (ti4_4 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_5 > (EIF_INTEGER_32) -ti4_6)) && (EIF_BOOLEAN) (ti4_7 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_8 > (EIF_INTEGER_32) -ti4_9)) && (EIF_BOOLEAN) (ti4_10 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_11 > ((EIF_INTEGER_32) -1000L))) && (EIF_BOOLEAN) (ti4_12 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_13 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_14 > (EIF_INTEGER_32) -ti4_15)) && (EIF_BOOLEAN) (ti4_16 <= ((EIF_INTEGER_32) 0L)))) {
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
			ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5595, "days_in_current_month", loc1))(loc1)).it_i4);
			tb1 = (EIF_BOOLEAN) (ti4_1 > (EIF_INTEGER_32) -ti4_2);
		}
		Result = (EIF_BOOLEAN) tb1;
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(12);
		RTCT("positive_definition", EX_POST);
		tb1 = '\01';
		if (Result) {
			tb2 = '\01';
			ur1 = RTCCL(Current);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ur1 = RTCCL(tr1);
			tb3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(1343, "is_less_equal", arg1))(arg1, ur1x)).it_b);
			if (tb3) {
				tb3 = '\0';
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
				ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
				ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
				ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5466, dtype))(Current)).it_i4);
				ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
				if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_3 < ti4_4)) && (EIF_BOOLEAN) (ti4_5 >= ((EIF_INTEGER_32) 0L)))) {
					tb4 = '\01';
					tb5 = '\01';
					ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
					ur1 = RTCCL(Current);
					tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5582, "day", tr1))(tr1)).it_i4);
					if ((EIF_BOOLEAN) (ti4_1 >= ti4_2)) {
						ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
						ur1 = RTCCL(Current);
						tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
						ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5596, "days_in_previous_month", tr1))(tr1)).it_i4);
						tb5 = (EIF_BOOLEAN) (ti4_1 < ti4_2);
					}
					if (!(tb5)) {
						tb5 = '\01';
						ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
						ur1 = RTCCL(Current);
						tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
						ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5582, "day", tr1))(tr1)).it_i4);
						if ((EIF_BOOLEAN) (ti4_1 < ti4_2)) {
							ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
							ur1 = RTCCL(Current);
							tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
							ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5595, "days_in_current_month", tr1))(tr1)).it_i4);
							tb5 = (EIF_BOOLEAN) (ti4_1 < ti4_2);
						}
						tb4 = tb5;
					}
					tb3 = tb4;
				}
				tb2 = tb3;
			}
			tb1 = tb2;
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(13);
		RTCT("negative_definition", EX_POST);
		tb1 = '\01';
		if (Result) {
			tb2 = '\01';
			ur1 = RTCCL(Current);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ur1 = RTCCL(tr1);
			tb3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(1345, "is_greater_equal", arg1))(arg1, ur1x)).it_b);
			if (tb3) {
				tb3 = '\0';
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
				ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
				ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
				ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5466, dtype))(Current)).it_i4);
				ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
				if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 <= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_3 > (EIF_INTEGER_32) -ti4_4)) && (EIF_BOOLEAN) (ti4_5 <= ((EIF_INTEGER_32) 0L)))) {
					ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
					ur1 = RTCCL(Current);
					tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5595, "days_in_current_month", tr1))(tr1)).it_i4);
					tb3 = (EIF_BOOLEAN) (ti4_1 > (EIF_INTEGER_32) -ti4_2);
				}
				tb2 = tb3;
			}
			tb1 = tb2;
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(14);
		RTCT("positive_definition", EX_POST);
		tb1 = '\01';
		if (Result) {
			tb2 = '\01';
			ur1 = RTCCL(Current);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ur1 = RTCCL(tr1);
			tb3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(1343, "is_less_equal", arg1))(arg1, ur1x)).it_b);
			if (tb3) {
				tb3 = '\0';
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5497, dtype))(Current)).it_i4);
				ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_6 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
				ti4_7 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_8 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_9 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
				ti4_10 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				ti4_11 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				ti4_12 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
				ti4_13 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
				ti4_14 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
				ti4_15 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5466, dtype))(Current)).it_i4);
				ti4_16 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
				if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 < ti4_3)) && (EIF_BOOLEAN) (ti4_4 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_5 < ti4_6)) && (EIF_BOOLEAN) (ti4_7 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_8 < ti4_9)) && (EIF_BOOLEAN) (ti4_10 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_11 < ((EIF_INTEGER_32) 1000L))) && (EIF_BOOLEAN) (ti4_12 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_13 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_14 < ti4_15)) && (EIF_BOOLEAN) (ti4_16 >= ((EIF_INTEGER_32) 0L)))) {
					tb4 = '\01';
					tb5 = '\01';
					ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
					ur1 = RTCCL(Current);
					tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5582, "day", tr1))(tr1)).it_i4);
					if ((EIF_BOOLEAN) (ti4_1 >= ti4_2)) {
						ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
						ur1 = RTCCL(Current);
						tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
						ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5596, "days_in_previous_month", tr1))(tr1)).it_i4);
						tb5 = (EIF_BOOLEAN) (ti4_1 < ti4_2);
					}
					if (!(tb5)) {
						tb5 = '\01';
						ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
						ur1 = RTCCL(Current);
						tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
						ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5582, "day", tr1))(tr1)).it_i4);
						if ((EIF_BOOLEAN) (ti4_1 < ti4_2)) {
							ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
							ur1 = RTCCL(Current);
							tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
							ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5595, "days_in_current_month", tr1))(tr1)).it_i4);
							tb5 = (EIF_BOOLEAN) (ti4_1 < ti4_2);
						}
						tb4 = tb5;
					}
					tb3 = tb4;
				}
				tb2 = tb3;
			}
			tb1 = tb2;
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(15);
		RTCT("negative_definition", EX_POST);
		tb1 = '\01';
		if (Result) {
			tb2 = '\01';
			ur1 = RTCCL(Current);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ur1 = RTCCL(tr1);
			tb3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(1345, "is_greater_equal", arg1))(arg1, ur1x)).it_b);
			if (tb3) {
				tb3 = '\0';
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5497, dtype))(Current)).it_i4);
				ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_6 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
				ti4_7 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_8 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_9 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
				ti4_10 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				ti4_11 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				ti4_12 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
				ti4_13 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
				ti4_14 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
				ti4_15 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5466, dtype))(Current)).it_i4);
				ti4_16 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
				if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 <= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 > (EIF_INTEGER_32) -ti4_3)) && (EIF_BOOLEAN) (ti4_4 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_5 > (EIF_INTEGER_32) -ti4_6)) && (EIF_BOOLEAN) (ti4_7 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_8 > (EIF_INTEGER_32) -ti4_9)) && (EIF_BOOLEAN) (ti4_10 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_11 > ((EIF_INTEGER_32) -1000L))) && (EIF_BOOLEAN) (ti4_12 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_13 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_14 > (EIF_INTEGER_32) -ti4_15)) && (EIF_BOOLEAN) (ti4_16 <= ((EIF_INTEGER_32) 0L)))) {
					ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
					ur1 = RTCCL(Current);
					tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5595, "days_in_current_month", tr1))(tr1)).it_i4);
					tb3 = (EIF_BOOLEAN) (ti4_1 > (EIF_INTEGER_32) -ti4_2);
				}
				tb2 = tb3;
			}
			tb1 = tb2;
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(16);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
#undef up1
#undef ur1
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.is_time_canonical */
EIF_TYPED_VALUE F1032_7965 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "is_time_canonical";
	RTEX;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_INTEGER_32 ti4_5;
	EIF_INTEGER_32 ti4_6;
	EIF_INTEGER_32 ti4_7;
	EIF_INTEGER_32 ti4_8;
	EIF_INTEGER_32 ti4_9;
	EIF_INTEGER_32 ti4_10;
	EIF_INTEGER_32 ti4_11;
	EIF_INTEGER_32 ti4_12;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_BOOL, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 0, 14072);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14072);
	RTIV(Current, RTAL);
	RTHOOK(1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
	if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L))) {
		RTHOOK(2);
		RTDBGAL(Current, 0, 0x04000000, 1,0); /* Result */
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		Result = (EIF_BOOLEAN) (EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN)(ti4_2 == ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN)(ti4_3 == ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN)(ti4_4 == ((EIF_INTEGER_32) 0L)));
	} else {
		RTHOOK(3);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
		if ((EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L))) {
			RTHOOK(4);
			RTDBGAL(Current, 0, 0x04000000, 1,0); /* Result */
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
			ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
			ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5497, dtype))(Current)).it_i4);
			ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
			ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
			ti4_6 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
			ti4_7 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
			ti4_8 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
			ti4_9 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
			ti4_10 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
			ti4_11 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
			ti4_12 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
			Result = (EIF_BOOLEAN) (EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 < ti4_3)) && (EIF_BOOLEAN) (ti4_4 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_5 < ti4_6)) && (EIF_BOOLEAN) (ti4_7 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_8 < ti4_9)) && (EIF_BOOLEAN) (ti4_10 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_11 < ((EIF_INTEGER_32) 1000L))) && (EIF_BOOLEAN) (ti4_12 >= ((EIF_INTEGER_32) 0L)));
		} else {
			RTHOOK(5);
			RTDBGAL(Current, 0, 0x04000000, 1,0); /* Result */
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
			ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
			ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5497, dtype))(Current)).it_i4);
			ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
			ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
			ti4_6 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
			ti4_7 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
			ti4_8 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
			ti4_9 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
			ti4_10 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
			ti4_11 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
			ti4_12 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
			Result = (EIF_BOOLEAN) (EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 <= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 > (EIF_INTEGER_32) -ti4_3)) && (EIF_BOOLEAN) (ti4_4 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_5 > (EIF_INTEGER_32) -ti4_6)) && (EIF_BOOLEAN) (ti4_7 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_8 > (EIF_INTEGER_32) -ti4_9)) && (EIF_BOOLEAN) (ti4_10 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_11 > ((EIF_INTEGER_32) -1000L))) && (EIF_BOOLEAN) (ti4_12 <= ((EIF_INTEGER_32) 0L)));
		}
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(6);
		RTCT("positive_definition", EX_POST);
		tb1 = '\01';
		if (Result) {
			tb2 = '\01';
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
			if ((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 0L))) {
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
				ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_6 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_7 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
				ti4_8 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				ti4_9 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				tb2 = (EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_3 < ti4_4)) && (EIF_BOOLEAN) (ti4_5 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_6 < ti4_7)) && (EIF_BOOLEAN) (ti4_8 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_9 < ((EIF_INTEGER_32) 1000L)));
			}
			tb1 = tb2;
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(7);
		RTCT("negative_definition", EX_POST);
		tb1 = '\01';
		if (Result) {
			tb2 = '\01';
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
			if ((EIF_BOOLEAN) (ti4_1 <= ((EIF_INTEGER_32) 0L))) {
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
				ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_6 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_7 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
				ti4_8 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				ti4_9 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				tb2 = (EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 <= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_3 > (EIF_INTEGER_32) -ti4_4)) && (EIF_BOOLEAN) (ti4_5 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_6 > (EIF_INTEGER_32) -ti4_7)) && (EIF_BOOLEAN) (ti4_8 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_9 > ((EIF_INTEGER_32) -1000L)));
			}
			tb1 = tb2;
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(8);
		RTCT("zero_definition", EX_POST);
		tb1 = '\01';
		if (Result) {
			tb2 = '\01';
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
			if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L))) {
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				tb2 = (EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN)(ti4_2 == ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN)(ti4_3 == ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN)(ti4_4 == ((EIF_INTEGER_32) 0L)));
			}
			tb1 = tb2;
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(9);
		RTCT("positive_definition", EX_POST);
		tb1 = '\01';
		if (Result) {
			tb2 = '\01';
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
			if ((EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L))) {
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5497, dtype))(Current)).it_i4);
				ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_6 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
				ti4_7 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_8 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_9 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
				ti4_10 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				ti4_11 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				ti4_12 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
				tb2 = (EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 >= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 < ti4_3)) && (EIF_BOOLEAN) (ti4_4 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_5 < ti4_6)) && (EIF_BOOLEAN) (ti4_7 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_8 < ti4_9)) && (EIF_BOOLEAN) (ti4_10 >= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_11 < ((EIF_INTEGER_32) 1000L))) && (EIF_BOOLEAN) (ti4_12 >= ((EIF_INTEGER_32) 0L)));
			}
			tb1 = tb2;
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(10);
		RTCT("negative_definition", EX_POST);
		tb1 = '\01';
		if (Result) {
			tb2 = '\01';
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
			if ((EIF_BOOLEAN) (ti4_1 < ((EIF_INTEGER_32) 0L))) {
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
				ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5497, dtype))(Current)).it_i4);
				ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_5 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
				ti4_6 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5496, dtype))(Current)).it_i4);
				ti4_7 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_8 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
				ti4_9 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5492, dtype))(Current)).it_i4);
				ti4_10 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				ti4_11 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
				ti4_12 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
				tb2 = (EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (ti4_1 <= ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (ti4_2 > (EIF_INTEGER_32) -ti4_3)) && (EIF_BOOLEAN) (ti4_4 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_5 > (EIF_INTEGER_32) -ti4_6)) && (EIF_BOOLEAN) (ti4_7 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_8 > (EIF_INTEGER_32) -ti4_9)) && (EIF_BOOLEAN) (ti4_10 <= ((EIF_INTEGER_32) 0L))) && (EIF_BOOLEAN) (ti4_11 > ((EIF_INTEGER_32) -1000L))) && (EIF_BOOLEAN) (ti4_12 <= ((EIF_INTEGER_32) 0L)));
			}
			tb1 = tb2;
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(11);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
}

/* {DT_DATE_TIME_DURATION}.date_duration */
EIF_TYPED_VALUE F1032_7966 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "date_duration";
	RTEX;
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(3);
	RTLR(0,tr1);
	RTLR(1,Current);
	RTLR(2,Result);
	RTLIU(3);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 0, 14073);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14073);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(Current, 0, 0xF8000401, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(1025, 0x01).id);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
	ui4_1 = ti4_1;
	ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
	ui4_2 = ti4_2;
	ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
	ui4_3 = ti4_3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(5616, Dtype(tr1)))(tr1, ui4_1x, ui4_2x, ui4_3x);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(2);
		RTCT("date_not_void", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(3);
		RTCT("year_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5638, "year", Result));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(4);
		RTCT("month_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5637, "month", Result));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(5);
		RTCT("day_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5636, "day", Result));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(6);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ui4_1
#undef ui4_2
#undef ui4_3
}

/* {DT_DATE_TIME_DURATION}.time_duration */
EIF_TYPED_VALUE F1032_7967 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "time_duration";
	RTEX;
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE ui4_4x = {{0}, SK_INT32};
#define ui4_4 ui4_4x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(3);
	RTLR(0,tr1);
	RTLR(1,Current);
	RTLR(2,Result);
	RTLIU(3);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 0, 14074);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14074);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(Current, 0, 0xF8000403, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(1027, 0x01).id);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
	ui4_1 = ti4_1;
	ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
	ui4_2 = ti4_2;
	ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
	ui4_3 = ti4_3;
	ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
	ui4_4 = ti4_4;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(5651, Dtype(tr1)))(tr1, ui4_1x, ui4_2x, ui4_3x, ui4_4x);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(2);
		RTCT("time_not_void", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(3);
		RTCT("hour_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5676, "hour", Result));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(4);
		RTCT("minute_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5675, "minute", Result));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(5);
		RTCT("second_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5674, "second", Result));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(6);
		RTCT("millisecond_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5673, "millisecond", Result));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(7);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef ui4_4
}

/* {DT_DATE_TIME_DURATION}.hash_code */
EIF_TYPED_VALUE F1032_7968 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "hash_code";
	RTEX;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_INTEGER_32 ti4_5;
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_INT32, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 0, 14075);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14075);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(Current, 0, 0x10000000, 1,0); /* Result */
	Result = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
	ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5489, dtype))(Current)).it_i4);
	ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
	ti4_4 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5467, dtype))(Current)).it_i4);
	ti4_5 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
	Result = (EIF_INTEGER_32) (EIF_INTEGER_32) ((EIF_INTEGER_32) ((EIF_INTEGER_32) (Result + (EIF_INTEGER_32) (ti4_1 * ti4_2)) + (EIF_INTEGER_32) (ti4_3 * ti4_4)) + ti4_5);
	RTHOOK(2);
	if ((EIF_BOOLEAN) (Result < ((EIF_INTEGER_32) 0L))) {
		RTHOOK(3);
		RTDBGAL(Current, 0, 0x10000000, 1,0); /* Result */
		Result = (EIF_INTEGER_32) (EIF_INTEGER_32) -(EIF_INTEGER_32) (Result + ((EIF_INTEGER_32) 1L));
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(4);
		RTCT("good_hash_value", EX_POST);
		if ((EIF_BOOLEAN) (Result >= ((EIF_INTEGER_32) 0L))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(5);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
}

/* {DT_DATE_TIME_DURATION}.date_time */
EIF_TYPED_VALUE F1032_7969 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "date_time";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,ur1);
	RTLR(3,tr1);
	RTLR(4,Result);
	RTLIU(5);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 1, 14076);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14076);
	RTCC(arg1, 1031, l_feature_name, 1, eif_new_type(1030, 0x01), 0x01);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("a_time_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(Current, 0, 0xF8000406, 0,0); /* Result */
	ur1 = RTCCL(Current);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
		RTCT("absolute_time_not_void", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(4);
		RTCT("definition", EX_POST);
		ur1 = RTCCL(Current);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(tr1);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(11, "is_equal", Result))(Result, ur1x)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(5);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.set_canonical */
void F1032_7970 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "set_canonical";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REFERENCE tr3 = NULL;
	EIF_REFERENCE tr4 = NULL;
	EIF_BOOLEAN tb1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(9);
	RTLR(0,arg1);
	RTLR(1,tr1);
	RTLR(2,Current);
	RTLR(3,tr2);
	RTLR(4,loc1);
	RTLR(5,ur1);
	RTLR(6,ur2);
	RTLR(7,tr3);
	RTLR(8,tr4);
	RTLIU(9);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 1031, Current, 1, 1, 14077);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14077);
	RTCC(arg1, 1031, l_feature_name, 1, RTWCT(5571, dtype, Dftype(Current)), 0x00);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("a_date_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	if (RTAL & CK_ENSURE) {
		in_assertion = ~0;
		RTE_OT
		tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5570, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		tr1 = tr2;
		tr2 = NULL;
		RTE_O
		tr2 = RTLA;
		RTE_OE
		in_assertion = 0;
	}
	RTHOOK(2);
	RTDBGAL(Current, 1, 0xF8000406, 0, 0); /* loc1 */
	loc1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5731, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTHOOK(3);
	ur1 = RTCCL(arg1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5599, "set_date", loc1))(loc1, ur1x);
	RTHOOK(4);
	ur1 = RTCCL(arg1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5687, "set_time", loc1))(loc1, ur1x);
	RTHOOK(5);
	ur1 = RTCCL(Current);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5579, "add_duration", loc1))(loc1, ur1x);
	RTHOOK(6);
	ur1 = RTCCL(arg1);
	ur2 = RTCCL(loc1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5618, dtype))(Current, ur1x, ur2x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(7);
		RTCT("is_canonical", EX_POST);
		ur1 = RTCCL(arg1);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5620, dtype))(Current, ur1x)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(8);
		RTCT("same_duration", EX_POST);
		ur1 = RTCCL(Current);
		tr3 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTCO(tr2);
		ur1 = RTCCL(tr1);
		tr4 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5577, "plus", arg1))(arg1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(tr4);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(11, "is_equal", tr3))(tr3, ur1x)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
#undef up1
#undef ur1
#undef ur2
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.set_time_canonical */
void F1032_7971 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "set_time_canonical";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc4 = (EIF_INTEGER_32) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_REFERENCE tr3 = NULL;
	EIF_REFERENCE tr4 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_BOOLEAN tb1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(6);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLR(2,tr2);
	RTLR(3,tr3);
	RTLR(4,tr4);
	RTLR(5,ur1);
	RTLIU(6);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_INT32, &loc3);
	RTLU(SK_INT32, &loc4);
	
	RTEAA(l_feature_name, 1031, Current, 4, 0, 14078);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14078);
	RTIV(Current, RTAL);
	if (RTAL & CK_ENSURE) {
		in_assertion = ~0;
		RTE_OT
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		ti4_1 = ti4_2;
		tr1 = NULL;
		RTE_O
		tr1 = RTLA;
		RTE_OE
		RTE_OT
		ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		ti4_2 = ti4_3;
		tr2 = NULL;
		RTE_O
		tr2 = RTLA;
		RTE_OE
		RTE_OT
		tr4 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5570, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		tr3 = tr4;
		tr4 = NULL;
		RTE_O
		tr4 = RTLA;
		RTE_OE
		in_assertion = 0;
	}
	RTHOOK(1);
	RTDBGAL(Current, 4, 0x10000000, 1, 0); /* loc4 */
	loc4 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
	RTHOOK(2);
	RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
	loc3 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
	RTHOOK(3);
	RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
	loc2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
	RTHOOK(4);
	if ((EIF_BOOLEAN) (loc2 < ((EIF_INTEGER_32) 0L))) {
		RTHOOK(5);
		RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
		loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) -loc2;
		RTHOOK(6);
		RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
		loc1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc1 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc1 - (EIF_INTEGER_32) (loc2 / ti4_3));
		RTHOOK(7);
		RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
		ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) -(EIF_INTEGER_32) (loc2 % ti4_3);
		RTHOOK(8);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) (loc1 > ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN)(loc2 != ((EIF_INTEGER_32) 0L)))) {
			RTHOOK(9);
			RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
			loc1--;
			RTHOOK(10);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
			loc2 += ti4_3;
		}
	} else {
		RTHOOK(11);
		RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
		loc1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc1 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc1 + (EIF_INTEGER_32) (loc2 / ti4_3));
		RTHOOK(12);
		RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
		ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc2 %= ti4_3;
		RTHOOK(13);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) (loc1 < ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN)(loc2 != ((EIF_INTEGER_32) 0L)))) {
			RTHOOK(14);
			RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
			loc1++;
			RTHOOK(15);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
			loc2 -= ti4_3;
		}
	}
	RTHOOK(16);
	ui4_1 = loc2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5725, dtype))(Current, ui4_1x);
	RTHOOK(17);
	ui4_1 = loc4;
	ui4_2 = loc3;
	ui4_3 = loc1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(5623, dtype))(Current, ui4_1x, ui4_2x, ui4_3x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(18);
		RTCT("is_canonical", EX_POST);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5654, dtype))(Current)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(19);
		RTCT("same_duration", EX_POST);
		RTCO(tr4);
		ur1 = RTCCL(tr3);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(11, dtype))(Current, ur1x)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(20);
		RTCT("same_year", EX_POST);
		ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		RTCO(tr1);
		if ((EIF_BOOLEAN)(ti4_3 == ti4_1)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(21);
		RTCT("same_month", EX_POST);
		ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		RTCO(tr2);
		if ((EIF_BOOLEAN)(ti4_3 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(22);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(6);
	RTEE;
#undef up1
#undef ur1
#undef ui4_1
#undef ui4_2
#undef ui4_3
}

/* {DT_DATE_TIME_DURATION}.set_date_duration */
void F1032_7972 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "set_date_duration";
	RTEX;
#define arg1 arg1x.it_r
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(2);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 1, 14079);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14079);
	RTCC(arg1, 1031, l_feature_name, 1, RTWCT(5710, dtype, Dftype(Current)), 0x00);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("a_date_duration_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 5638, 0x10000000, 1); /* year */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5638, "year", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 5637, 0x10000000, 1); /* month */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5637, "month", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(4);
	RTDBGAA(Current, dtype, 5636, 0x10000000, 1); /* day */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype)) = (EIF_INTEGER_32) ti4_1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(5);
		RTCT("year_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5638, "year", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(6);
		RTCT("month_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5637, "month", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(7);
		RTCT("day_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(8);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.set_time_duration */
void F1032_7973 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "set_time_duration";
	RTEX;
#define arg1 arg1x.it_r
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(2);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 1, 14080);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14080);
	RTCC(arg1, 1031, l_feature_name, 1, RTWCT(5711, dtype, Dftype(Current)), 0x00);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("a_time_duration_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 5676, 0x10000000, 1); /* hour */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5676, "hour", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 5675, 0x10000000, 1); /* minute */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5675, "minute", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(4);
	RTDBGAA(Current, dtype, 5674, 0x10000000, 1); /* second */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5674, "second", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(5);
	RTDBGAA(Current, dtype, 5673, 0x10000000, 1); /* millisecond */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5673, "millisecond", arg1));
	*(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype)) = (EIF_INTEGER_32) ti4_1;
	if (RTAL & CK_ENSURE) {
		RTHOOK(6);
		RTCT("hour_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5676, "hour", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(7);
		RTCT("minute_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5675, "minute", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(8);
		RTCT("second_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5674, "second", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(9);
		RTCT("millisecond_set", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5673, "millisecond", arg1));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(10);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.plus */
EIF_TYPED_VALUE F1032_7974 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "plus";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE ui4_4x = {{0}, SK_INT32};
#define ui4_4 ui4_4x.it_i4
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(3);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,Result);
	RTLIU(3);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 1, 14081);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14081);
	RTCC(arg1, 1031, l_feature_name, 1, eif_new_type(1031, 0x01),0);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("other_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(Current, 0, 0xF8000407, 0,0); /* Result */
	Result = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5570, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTHOOK(3);
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5638, "year", arg1));
	ui4_1 = ti4_1;
	ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5637, "month", arg1));
	ui4_2 = ti4_2;
	ti4_3 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
	ui4_3 = ti4_3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5627, "add_years_months_days", Result))(Result, ui4_1x, ui4_2x, ui4_3x);
	RTHOOK(4);
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5676, "hour", arg1));
	ui4_1 = ti4_1;
	ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5675, "minute", arg1));
	ui4_2 = ti4_2;
	ti4_3 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5674, "second", arg1));
	ui4_3 = ti4_3;
	ti4_4 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5673, "millisecond", arg1));
	ui4_4 = ti4_4;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5665, "add_precise_hours_minutes_seconds", Result))(Result, ui4_1x, ui4_2x, ui4_3x, ui4_4x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(5);
		RTCT("addition_not_void", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(6);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef ui4_4
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.minus */
EIF_TYPED_VALUE F1032_7975 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "minus";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE ui4_4x = {{0}, SK_INT32};
#define ui4_4 ui4_4x.it_i4
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(3);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,Result);
	RTLIU(3);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 1, 14082);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14082);
	RTCC(arg1, 1031, l_feature_name, 1, eif_new_type(1031, 0x01),0);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("other_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(Current, 0, 0xF8000407, 0,0); /* Result */
	Result = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5570, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTHOOK(3);
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5638, "year", arg1));
	ui4_1 = (EIF_INTEGER_32) -ti4_1;
	ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5637, "month", arg1));
	ui4_2 = (EIF_INTEGER_32) -ti4_2;
	ti4_3 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
	ui4_3 = (EIF_INTEGER_32) -ti4_3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5627, "add_years_months_days", Result))(Result, ui4_1x, ui4_2x, ui4_3x);
	RTHOOK(4);
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5676, "hour", arg1));
	ui4_1 = (EIF_INTEGER_32) -ti4_1;
	ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5675, "minute", arg1));
	ui4_2 = (EIF_INTEGER_32) -ti4_2;
	ti4_3 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5674, "second", arg1));
	ui4_3 = (EIF_INTEGER_32) -ti4_3;
	ti4_4 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5673, "millisecond", arg1));
	ui4_4 = (EIF_INTEGER_32) -ti4_4;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5665, "add_precise_hours_minutes_seconds", Result))(Result, ui4_1x, ui4_2x, ui4_3x, ui4_4x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(5);
		RTCT("subtraction_not_void", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(6);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef ui4_4
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.opposite */
EIF_TYPED_VALUE F1032_7976 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "opposite";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE ui4_4x = {{0}, SK_INT32};
#define ui4_4 ui4_4x.it_i4
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,Result);
	RTLIU(2);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 0, 14083);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14083);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(Current, 0, 0xF8000407, 0,0); /* Result */
	Result = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5570, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTHOOK(2);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
	ui4_1 = (EIF_INTEGER_32) -ti4_1;
	ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
	ui4_2 = (EIF_INTEGER_32) -ti4_2;
	ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
	ui4_3 = (EIF_INTEGER_32) -ti4_3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5623, "set_year_month_day", Result))(Result, ui4_1x, ui4_2x, ui4_3x);
	RTHOOK(3);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5676, dtype));
	ui4_1 = (EIF_INTEGER_32) -ti4_1;
	ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5675, dtype));
	ui4_2 = (EIF_INTEGER_32) -ti4_2;
	ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5674, dtype));
	ui4_3 = (EIF_INTEGER_32) -ti4_3;
	ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5673, dtype));
	ui4_4 = (EIF_INTEGER_32) -ti4_4;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5659, "set_precise_hour_minute_second", Result))(Result, ui4_1x, ui4_2x, ui4_3x, ui4_4x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(4);
		RTCT("unary_minus_not_void", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(5);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef ui4_4
}

/* {DT_DATE_TIME_DURATION}.is_less */
EIF_TYPED_VALUE F1032_7977 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "is_less";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
#define arg1 arg1x.it_r
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(2);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_BOOL, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_INT32, &loc3);
	
	RTEAA(l_feature_name, 1031, Current, 3, 1, 14084);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14084);
	RTCC(arg1, 1031, l_feature_name, 1, eif_new_type(1031, 0x01),0);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("other_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
	loc1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5638, "year", arg1));
	ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5466, dtype))(Current)).it_i4);
	ti4_3 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
	ti4_4 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5637, "month", arg1));
	loc1 = (EIF_INTEGER_32) (EIF_INTEGER_32) ((EIF_INTEGER_32) ((EIF_INTEGER_32) (loc1 - ti4_1) * ti4_2) + (EIF_INTEGER_32) (ti4_3 - ti4_4));
	RTHOOK(3);
	RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
	loc3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5656, "millisecond_count", arg1))(arg1)).it_i4);
	loc3 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc3 - ti4_1);
	RTHOOK(4);
	if ((EIF_BOOLEAN) (loc3 < ((EIF_INTEGER_32) 0L))) {
		RTHOOK(5);
		RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
		loc3 = (EIF_INTEGER_32) (EIF_INTEGER_32) -loc3;
		RTHOOK(6);
		RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
		loc2 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) ((EIF_INTEGER_32) (loc2 - ti4_1) - (EIF_INTEGER_32) (loc3 / ti4_2));
		RTHOOK(7);
		RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc3 = (EIF_INTEGER_32) (EIF_INTEGER_32) -(EIF_INTEGER_32) (loc3 % ti4_1);
		RTHOOK(8);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) (loc2 > ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN)(loc3 != ((EIF_INTEGER_32) 0L)))) {
			RTHOOK(9);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			loc2--;
			RTHOOK(10);
			RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
			loc3 += ti4_1;
		}
	} else {
		RTHOOK(11);
		RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
		loc2 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
		ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
		ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) ((EIF_INTEGER_32) (loc2 - ti4_1) + (EIF_INTEGER_32) (loc3 / ti4_2));
		RTHOOK(12);
		RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
		loc3 %= ti4_1;
		RTHOOK(13);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) (loc2 < ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN)(loc3 != ((EIF_INTEGER_32) 0L)))) {
			RTHOOK(14);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			loc2++;
			RTHOOK(15);
			RTDBGAL(Current, 3, 0x10000000, 1, 0); /* loc3 */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
			loc3 -= ti4_1;
		}
	}
	RTHOOK(16);
	if ((EIF_BOOLEAN)(loc1 == ((EIF_INTEGER_32) 0L))) {
		RTHOOK(17);
		RTDBGAL(Current, 0, 0x04000000, 1,0); /* Result */
		Result = (EIF_BOOLEAN) (EIF_BOOLEAN) ((EIF_BOOLEAN) (loc2 < ((EIF_INTEGER_32) 0L)) || (EIF_BOOLEAN) ((EIF_BOOLEAN)(loc2 == ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (loc3 < ((EIF_INTEGER_32) 0L))));
	} else {
		RTHOOK(18);
		if ((EIF_BOOLEAN) (loc1 < ((EIF_INTEGER_32) 0L))) {
			RTHOOK(19);
			RTDBGAL(Current, 0, 0x04000000, 1,0); /* Result */
			Result = (EIF_BOOLEAN) (EIF_BOOLEAN) ((EIF_BOOLEAN) (loc2 < ((EIF_INTEGER_32) 0L)) || (EIF_BOOLEAN) ((EIF_BOOLEAN)(loc2 == ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (loc3 <= ((EIF_INTEGER_32) 0L))));
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(20);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(6);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.is_equal */
EIF_TYPED_VALUE F1032_7978 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "is_equal";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLR(3,ur1);
	RTLR(4,ur2);
	RTLIU(5);
	RTLU (SK_BOOL, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 1, 14085);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14085);
	RTCC(arg1, 1031, l_feature_name, 1, eif_new_type(1031, 0x01),0);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("other_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5230, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTNHOOK(2,1);
	ur1 = RTCCL(Current);
	ur2 = RTCCL(arg1);
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5090, "same_types", tr1))(tr1, ur1x, ur2x)).it_b);
	if (tb1) {
		RTHOOK(3);
		RTDBGAL(Current, 0, 0x04000000, 1,0); /* Result */
		ur1 = RTCCL(arg1);
		Result = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5730, dtype))(Current, ur1x)).it_b);
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(4);
		RTCT("symmetric", EX_POST);
		if ((!(Result) || (RTEQ(arg1, Current)))) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(5);
		RTCT("consistent", EX_POST);
		tb1 = '\01';
		ur1 = RTCCL(arg1);
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(12, dtype))(Current, ur1x)).it_b);
		if (tb2) {
			tb1 = Result;
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(6);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
#undef up1
#undef ur1
#undef ur2
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.same_date_time_duration */
EIF_TYPED_VALUE F1032_7979 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "same_date_time_duration";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
#define arg1 arg1x.it_r
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_INTEGER_32 ti4_4;
	EIF_INTEGER_32 ti4_5;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(2);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_BOOL, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	
	RTEAA(l_feature_name, 1031, Current, 2, 1, 14086);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14086);
	RTCC(arg1, 1031, l_feature_name, 1, eif_new_type(1031, 0x01), 0x01);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("other_not_void", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
	ti4_2 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5638, "year", arg1));
	ti4_3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5466, dtype))(Current)).it_i4);
	ti4_4 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
	ti4_5 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5637, "month", arg1));
	if ((EIF_BOOLEAN)((EIF_INTEGER_32) ((EIF_INTEGER_32) ((EIF_INTEGER_32) (ti4_1 - ti4_2) * ti4_3) + (EIF_INTEGER_32) (ti4_4 - ti4_5)) == ((EIF_INTEGER_32) 0L))) {
		RTHOOK(3);
		RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
		loc2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5656, dtype))(Current)).it_i4);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5656, "millisecond_count", arg1))(arg1)).it_i4);
		loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc2 - ti4_1);
		RTHOOK(4);
		if ((EIF_BOOLEAN) (loc2 < ((EIF_INTEGER_32) 0L))) {
			RTHOOK(5);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) -loc2;
			RTHOOK(6);
			RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
			loc1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
			ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
			ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
			loc1 = (EIF_INTEGER_32) (EIF_INTEGER_32) ((EIF_INTEGER_32) (loc1 - ti4_1) - (EIF_INTEGER_32) (loc2 / ti4_2));
			RTHOOK(7);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
			loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) -(EIF_INTEGER_32) (loc2 % ti4_1);
		} else {
			RTHOOK(8);
			RTDBGAL(Current, 1, 0x10000000, 1, 0); /* loc1 */
			loc1 = *(EIF_INTEGER_32 *)(Current + RTWA(5636, dtype));
			ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(5636, "day", arg1));
			ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
			loc1 = (EIF_INTEGER_32) (EIF_INTEGER_32) ((EIF_INTEGER_32) (loc1 - ti4_1) + (EIF_INTEGER_32) (loc2 / ti4_2));
			RTHOOK(9);
			RTDBGAL(Current, 2, 0x10000000, 1, 0); /* loc2 */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5495, dtype))(Current)).it_i4);
			loc2 %= ti4_1;
		}
		RTHOOK(10);
		RTDBGAL(Current, 0, 0x04000000, 1,0); /* Result */
		Result = (EIF_BOOLEAN) (EIF_BOOLEAN) ((EIF_BOOLEAN)(loc2 == ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN)(loc1 == ((EIF_INTEGER_32) 0L)));
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(11);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(5);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
#undef arg1
}

/* {DT_DATE_TIME_DURATION}.to_time_canonical */
EIF_TYPED_VALUE F1032_7980 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "to_time_canonical";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(3);
	RTLR(0,Current);
	RTLR(1,Result);
	RTLR(2,ur1);
	RTLIU(3);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 0, 14087);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14087);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(Current, 0, 0xF8000407, 0,0); /* Result */
	Result = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5570, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTHOOK(2);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(5657, "set_time_canonical", Result))(Result);
	if (RTAL & CK_ENSURE) {
		RTHOOK(3);
		RTCT("canonical_duration_not_void", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(4);
		RTCT("is_canonical", EX_POST);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5654, "is_canonical", Result))(Result)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(5);
		RTCT("same_duration", EX_POST);
		ur1 = RTCCL(Current);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(11, "is_equal", Result))(Result, ur1x)).it_b);
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(6);
		RTCT("same_year", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5638, "year", Result));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5638, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
		RTHOOK(7);
		RTCT("same_month", EX_POST);
		ti4_1 = *(EIF_INTEGER_32 *)(Result + RTVA(5637, "month", Result));
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(5637, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(8);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
}

/* {DT_DATE_TIME_DURATION}.tmp_date_time */
RTOID (F1032_7981)
EIF_TYPED_VALUE F1032_7981 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "tmp_date_time";
	RTEX;
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE ui4_4x = {{0}, SK_INT32};
#define ui4_4 ui4_4x.it_i4
	EIF_TYPED_VALUE ui4_5x = {{0}, SK_INT32};
#define ui4_5 ui4_5x.it_i4
	EIF_TYPED_VALUE ui4_6x = {{0}, SK_INT32};
#define ui4_6 ui4_6x.it_i4
	EIF_REFERENCE tr1 = NULL;
	RTCDD;
	RTSN;
	RTDA;
	RTLD;
	
#define Result RTOTRR
	RTOTDR(F1032_7981);
	dtype = Dtype(Current);

	RTLI(2);
	RTLR(0,tr1);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1031, Current, 0, 0, 14088);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1031, Current, 14088);
	RTIV(Current, RTAL);
	RTOTP;
	RTHOOK(1);
	RTDBGAL(Current, 0, 0xF8000406, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(1030, 0x01).id);
	ui4_1 = ((EIF_INTEGER_32) 1L);
	ui4_2 = ((EIF_INTEGER_32) 1L);
	ui4_3 = ((EIF_INTEGER_32) 1L);
	ui4_4 = ((EIF_INTEGER_32) 0L);
	ui4_5 = ((EIF_INTEGER_32) 0L);
	ui4_6 = ((EIF_INTEGER_32) 0L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(5712, Dtype(tr1)))(tr1, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(2);
		RTCT("tmp_date_time_not_void", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTOTE;
	RTHOOK(3);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef ui4_4
#undef ui4_5
#undef ui4_6
#undef Result
}

void EIF_Minit1032 (void)
{
	GTCX
	RTOTS (7981,F1032_7981)
}


#ifdef __cplusplus
}
#endif
