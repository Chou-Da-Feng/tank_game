#pragma once

struct bits
{
	unsigned char hit : 1;
	unsigned char speedup : 1;
	unsigned char sp_disable : 1;
	unsigned char mp_disbale : 1;
	unsigned char freeze : 1;
	unsigned char sp_up : 1;
	unsigned char mp_up : 1;
	unsigned char hp_up : 1;
};

union byte_bits
{
	bits b;
	unsigned char B;
};

struct vw
{
	float V;
	float W;
};

struct vxy
{
	float Vx;
	float Vy;
};

struct position
{
	float X;
	float Y;
	float Theta = 1.57;
};



struct points
{
	float HP;
	float SP;
	float MP;
};

struct profile
{
	char name[20];
	struct position pos;
	struct vw vel;
	struct points point;
	int t;
	union byte_bits status;
	float width = 20;

};

struct enemy_profile
{
	char name[20];
	struct position pos;
	struct vxy V;
	struct points point;
	union byte_bits status;
	float width = 20;
	bool enable = 1;
	bool potion_enble = 1;   //一開始藥水存在
	int obs_counter = 30;
	float potion_HP = 5;     //藥水加的生命值
};


//week4


struct weapon_profile
{
	char name[20];
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	int counter;
	float diameter = 10;
	bool enable = 0;
	bool bosswea_enable = 0;
};



struct item_profile     //溫泉 
{
	char c;
	struct position pos;
	int counter;
	float diameter = 15;
	bool enable = 1;
};


struct magic_profile
{
	char name[20];
	struct position pos[5][5];
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	int counter;
	float diameter = 25;
	bool enable = 0;
};

struct potion_profile
{
	char name[20];
	struct position pos;
	struct vxy V;
	struct points point;
	union byte_bits status;
	float width = 20;
	bool enable = 1;
};

struct level_system   //升級系統
{
	float level; //升級
	float exp;   //經驗值
	float obsdead; //敵人死亡數
};

struct enemy_weapon_profile
{
	char name[20];
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	int counter;
	float diameter = 15;
	bool enable = 1;
};



struct Round
{
	int stage = 0;
	int round1 = 1;
	bool tank_round = 1;
	bool enemy_round = 1;
	int compute_round_time = 0;
};