//////////////////////////////////////
////// VARIABLE DE VENTILADORES /////
//////////////////////////////////////

	float fan_rot ;

//////////////////////////////////
////// VARIABLES DE IRON MAN /////
/////////////////////////////////

	bool til45 = true;
	bool r1 = true;
	bool r2 = false;
	bool r3 = false;
	bool r4 = false;
	bool r5 = false;
	bool r6 = false;
	bool r7 = false;
	bool r8 = false;
	float pos_iron [] = {0,0};
	float giro = 0;
	float swing_iron = 0;


///////////////////////////////////////////
////// VARIABLES DEL HALCON MILENARIO /////
///////////////////////////////////////////

	float falcon_X ;
	float falcon_Y ;
	float falcon_Z ;

	float falcon_rot_X ;
	float falcon_rot_Y ;
	float falcon_rot_Z ;

	typedef struct _frame {
		float falcon_X;
		float falcon_X_INC;
		float falcon_Y;
		float falcon_Y_INC;
		float falcon_Z;
		float falcon_Z_INC;
		float falcon_rot_X;
		float falcon_rot_X_INC;
		float falcon_rot_Y;
		float falcon_rot_Y_INC;
		float falcon_rot_Z;
		float falcon_rot_Z_INC;
	} FALCON_FRAME ;

	FALCON_FRAME falcon_KeyFrame[19 + 1];

	int falcon_max_steps = 50;
	int falcon_curr_steps = 0;


	int falcon_FrameIndex = 19 ;
	bool falcon_play = false ;
	int falcon_playIndex = 0 ;

//////////////////////////////
////// VARIABLES DE PONG /////
//////////////////////////////

float leftbar_Y;
float rightbar_Y;
float ball_X;
float ball_Y;

typedef struct __frame {

	float leftbar_Y;
	float leftbar_Y_INC;

	float rightbar_Y;
	float rightbar_Y_INC;

	float ball_X;
	float ball_X_INC;
	float ball_Y;
	float ball_Y_INC;

} PONG_FRAME ;


PONG_FRAME pong_KeyFrame[8 + 1];

int pong_max_steps = 50;
int pong_curr_steps = 0;


int pong_FrameIndex = 8 ;
bool pong_play = false ;
int pong_playIndex = 0 ;


