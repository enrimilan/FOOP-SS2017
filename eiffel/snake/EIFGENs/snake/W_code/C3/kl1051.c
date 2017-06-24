/*
 * Code for class KL_SYSTEM_CLOCK
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F1051_8356(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1051_8357(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1051_8358(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1051_8359(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1051_8360(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1051_8361(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1051_8362(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1051_8363(EIF_REFERENCE);
extern void F1051_8364(EIF_REFERENCE);
extern void F1051_8365(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1051_8366(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1051_8367(EIF_REFERENCE);
extern void EIF_Minit1051(void);

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

/* {KL_SYSTEM_CLOCK}.make */
void F1051_8356 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "make";
	RTEX;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1050, Current, 0, 0, 14396);
	RTSA(Dtype(Current));
	RTSC;
	RTME(Dtype(Current), 0);
	RTGC;
	RTDBGEAA(1050, Current, 14396);
	RTIV(Current, RTAL);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(1);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {KL_SYSTEM_CLOCK}.year */
EIF_TYPED_VALUE F1051_8357 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6025,Dtype(Current)));
	return r;
}


/* {KL_SYSTEM_CLOCK}.month */
EIF_TYPED_VALUE F1051_8358 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6024,Dtype(Current)));
	return r;
}


/* {KL_SYSTEM_CLOCK}.day */
EIF_TYPED_VALUE F1051_8359 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6023,Dtype(Current)));
	return r;
}


/* {KL_SYSTEM_CLOCK}.hour */
EIF_TYPED_VALUE F1051_8360 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6022,Dtype(Current)));
	return r;
}


/* {KL_SYSTEM_CLOCK}.minute */
EIF_TYPED_VALUE F1051_8361 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6021,Dtype(Current)));
	return r;
}


/* {KL_SYSTEM_CLOCK}.second */
EIF_TYPED_VALUE F1051_8362 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6020,Dtype(Current)));
	return r;
}


/* {KL_SYSTEM_CLOCK}.millisecond */
EIF_TYPED_VALUE F1051_8363 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6019,Dtype(Current)));
	return r;
}


/* {KL_SYSTEM_CLOCK}.set_local_time */
void F1051_8364 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "set_local_time";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(3);
	RTLR(0,loc1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 1050, Current, 1, 0, 14404);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1050, Current, 14404);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(Current, 1, 0xF8000417, 0, 0); /* loc1 */
	loc1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6018, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTHOOK(2);
	if ((EIF_BOOLEAN)(loc1 == NULL)) {
		RTHOOK(3);
		RTDBGAL(Current, 1, 0xF8000417, 0, 0); /* loc1 */
		tr1 = RTLN(eif_new_type(1047, 0x01).id);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(32, Dtype(tr1)))(tr1);
		RTNHOOK(3,1);
		loc1 = (EIF_REFERENCE) RTCCL(tr1);
		RTHOOK(4);
		RTDBGAA(Current, dtype, 6018, 0xF8000417, 0); /* local_clock */
		RTAR(Current, loc1);
		*(EIF_REFERENCE *)(Current + RTWA(6018, dtype)) = (EIF_REFERENCE) RTCCL(loc1);
	} else {
		RTHOOK(5);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(5979, "update", loc1))(loc1);
	}
	RTHOOK(6);
	RTDBGAA(Current, dtype, 6025, 0x10000000, 1); /* year */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5980, "year_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6025, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(7);
	RTDBGAA(Current, dtype, 6024, 0x10000000, 1); /* month */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5981, "month_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6024, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(8);
	RTDBGAA(Current, dtype, 6023, 0x10000000, 1); /* day */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5982, "day_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6023, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(9);
	RTDBGAA(Current, dtype, 6022, 0x10000000, 1); /* hour */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5983, "hour_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6022, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(10);
	RTDBGAA(Current, dtype, 6021, 0x10000000, 1); /* minute */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5984, "minute_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6021, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(11);
	RTDBGAA(Current, dtype, 6020, 0x10000000, 1); /* second */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5985, "second_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6020, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(12);
	RTDBGAA(Current, dtype, 6019, 0x10000000, 1); /* millisecond */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5986, "millisecond_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6019, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(13);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef up1
}

/* {KL_SYSTEM_CLOCK}.set_utc_time */
void F1051_8365 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "set_utc_time";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(3);
	RTLR(0,loc1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	
	RTEAA(l_feature_name, 1050, Current, 1, 0, 14405);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1050, Current, 14405);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(Current, 1, 0xF8000417, 0, 0); /* loc1 */
	loc1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6017, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTHOOK(2);
	if ((EIF_BOOLEAN)(loc1 == NULL)) {
		RTHOOK(3);
		RTDBGAL(Current, 1, 0xF8000417, 0, 0); /* loc1 */
		tr1 = RTLN(eif_new_type(1047, 0x01).id);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5977, Dtype(tr1)))(tr1);
		RTNHOOK(3,1);
		loc1 = (EIF_REFERENCE) RTCCL(tr1);
		RTHOOK(4);
		RTDBGAA(Current, dtype, 6017, 0xF8000417, 0); /* utc_clock */
		RTAR(Current, loc1);
		*(EIF_REFERENCE *)(Current + RTWA(6017, dtype)) = (EIF_REFERENCE) RTCCL(loc1);
	} else {
		RTHOOK(5);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(5979, "update", loc1))(loc1);
	}
	RTHOOK(6);
	RTDBGAA(Current, dtype, 6025, 0x10000000, 1); /* year */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5980, "year_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6025, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(7);
	RTDBGAA(Current, dtype, 6024, 0x10000000, 1); /* month */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5981, "month_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6024, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(8);
	RTDBGAA(Current, dtype, 6023, 0x10000000, 1); /* day */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5982, "day_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6023, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(9);
	RTDBGAA(Current, dtype, 6022, 0x10000000, 1); /* hour */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5983, "hour_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6022, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(10);
	RTDBGAA(Current, dtype, 6021, 0x10000000, 1); /* minute */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5984, "minute_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6021, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(11);
	RTDBGAA(Current, dtype, 6020, 0x10000000, 1); /* second */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5985, "second_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6020, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(12);
	RTDBGAA(Current, dtype, 6019, 0x10000000, 1); /* millisecond */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(5986, "millisecond_now", loc1))(loc1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(6019, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(13);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef up1
}

/* {KL_SYSTEM_CLOCK}.utc_clock */
EIF_TYPED_VALUE F1051_8366 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6017,Dtype(Current)));
	return r;
}


/* {KL_SYSTEM_CLOCK}.local_clock */
EIF_TYPED_VALUE F1051_8367 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6018,Dtype(Current)));
	return r;
}


void EIF_Minit1051 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
