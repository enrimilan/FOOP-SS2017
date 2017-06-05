/*
 * Code for class KEYBOARD_DEFINITION
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern EIF_TYPED_VALUE F958_7055(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F958_7056(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void EIF_Minit958(void);

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

/* {KEYBOARD_DEFINITION}.get_player_id_for_input */
EIF_TYPED_VALUE F958_7055 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "get_player_id_for_input";
	RTEX;
#define arg1 arg1x.it_c1
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_c1 = * (EIF_CHARACTER_8 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_INT32, &Result);
	RTLU(SK_CHAR8,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 957, Current, 0, 1, 13251);
	RTSA(Dtype(Current));
	RTSC;
	RTME(Dtype(Current), 0);
	RTGC;
	RTDBGEAA(957, Current, 13251);
	RTIV(Current, RTAL);
	RTHOOK(1);
	if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'a') || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 's')) || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'd')) || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'w'))) {
		RTHOOK(2);
		RTDBGAL(Current, 0, 0x10000000, 1,0); /* Result */
		Result = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	} else {
		RTHOOK(3);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'f') || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'g')) || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'h')) || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 't'))) {
			RTHOOK(4);
			RTDBGAL(Current, 0, 0x10000000, 1,0); /* Result */
			Result = (EIF_INTEGER_32) ((EIF_INTEGER_32) 2L);
		} else {
			RTHOOK(5);
			if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'j') || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'k')) || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'l')) || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'i'))) {
				RTHOOK(6);
				RTDBGAL(Current, 0, 0x10000000, 1,0); /* Result */
				Result = (EIF_INTEGER_32) ((EIF_INTEGER_32) 3L);
			} else {
				RTHOOK(7);
				RTDBGAL(Current, 0, 0x10000000, 1,0); /* Result */
				Result = (EIF_INTEGER_32) ((EIF_INTEGER_32) -1L);
			}
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
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
#undef arg1
}

/* {KEYBOARD_DEFINITION}.translate_input_to_direction */
EIF_TYPED_VALUE F958_7056 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "translate_input_to_direction";
	RTEX;
#define arg1 arg1x.it_c1
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_c1 = * (EIF_CHARACTER_8 *) arg1x.it_r;
	
	RTLI(2);
	RTLR(0,Result);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_REF, &Result);
	RTLU(SK_CHAR8,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 957, Current, 0, 1, 13252);
	RTSA(Dtype(Current));
	RTSC;
	RTME(Dtype(Current), 0);
	RTGC;
	RTDBGEAA(957, Current, 13252);
	RTIV(Current, RTAL);
	RTHOOK(1);
	if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'a') || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'f')) || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'j'))) {
		RTHOOK(2);
		RTDBGAL(Current, 0, 0xF80000E3, 0,0); /* Result */
		Result = RTMS_EX_H("LEFT",4,1279608404);
	} else {
		RTHOOK(3);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 's') || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'g')) || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'k'))) {
			RTHOOK(4);
			RTDBGAL(Current, 0, 0xF80000E3, 0,0); /* Result */
			Result = RTMS_EX_H("DOWN",4,1146050382);
		} else {
			RTHOOK(5);
			if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'w') || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 't')) || (EIF_BOOLEAN)(arg1 == (EIF_CHARACTER_8) 'i'))) {
				RTHOOK(6);
				RTDBGAL(Current, 0, 0xF80000E3, 0,0); /* Result */
				Result = RTMS_EX_H("UP",2,21840);
			} else {
				RTHOOK(7);
				RTDBGAL(Current, 0, 0xF80000E3, 0,0); /* Result */
				Result = RTMS_EX_H("RIGHT",5,1230038100);
			}
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
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef arg1
}

void EIF_Minit958 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
