#pragma once

#define wea_SIZE 50
#define PI 3.14159265359
#define G 8.8

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data_format.h"

struct profile tank_profile;
struct weapon_profile wea;
struct enemy_profile enemy;
struct enemy_weapon_profile enemy_wea;
struct Round round_count;
struct Round roundbool;

int wea_count = 0;
int wea_up = wea_SIZE;
int system_counter = 0;
float X = 0;
float Y = 0;
float Theta = 1.57;
int V = 0;
float W = 0;
float dt = 0.1;
float wea_time = 0.1;
float enemywea_time = 0.1;
float compute_round_time = 0;

// for 發射狀態
bool key = 1;
//bool round = 1; // 1: 玩家, 0: 敵人
bool isShot = 0; // 由button3把isShot: 0 -> 1
bool PLAY_ROUND = 1;
bool ENEMY_ROUND = 0;

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label5;

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(165, 43);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(105, 31);
			this->progressBar1->TabIndex = 2;
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(1076, 43);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(105, 31);
			this->progressBar2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(69, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 15);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(979, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 15);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(539, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 15);
			this->label3->TabIndex = 6;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(539, 78);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 15);
			this->label4->TabIndex = 7;
			this->label4->Text = L"label4";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(773, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 71);
			this->button1->TabIndex = 8;
			this->button1->Text = L"enemy_fire";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(523, 146);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 60);
			this->button2->TabIndex = 9;
			this->button2->Text = L"round_change";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(165, 99);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 68);
			this->button3->TabIndex = 10;
			this->button3->Text = L"fire";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(287, 9);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 54);
			this->button4->TabIndex = 11;
			this->button4->Text = L"UP";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(287, 146);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 50);
			this->button5->TabIndex = 12;
			this->button5->Text = L"Down";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(287, 78);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 51);
			this->button6->TabIndex = 13;
			this->button6->Text = L"STOP";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(539, 114);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 15);
			this->label5->TabIndex = 14;
			this->label5->Text = L"label5";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1282, 453);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->progressBar1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void plot_HMI(void)
		{
			Graphics^ e1 = this->CreateGraphics();
			e1->Clear(Color::WhiteSmoke);
			Pen^ pen_R = gcnew Pen(Color::Red, 2);  //坦克車
			Brush^ brush_BK = gcnew SolidBrush(Color::Gray); // map
			Pen^ pen_B10 = gcnew Pen(Color::Blue, 10); //weapon gun
			Pen^ pen_BL = gcnew Pen(Color::Blue, 2); // enemy

			int R_size = 30;     //tank_size
			int grid_width = 400;
			int grid_height = 400;
			int grid_resolution = 1;  //解析度
			int shift_x = (grid_width / 2); //
			int shift_y = (grid_height)+0;
			int Y_shift = 0;
			
			e1->FillRectangle(brush_BK, shift_x - 200 - R_size / 2, shift_y - 50 - R_size / 2, 1000, 100);

			// plot tank position 
			int x1 = (tank_profile.pos.X) / grid_resolution;
			int y1 = (tank_profile.pos.Y + Y_shift) / grid_resolution;

			e1->DrawEllipse(pen_R, shift_x + x1 - R_size / 2, shift_y - y1 - R_size / 2, R_size, R_size);  //戰車車身

			int dir_x1 = 40 * cos(tank_profile.pos.Theta);
			int dir_y1 = 40 * sin(tank_profile.pos.Theta);

			e1->DrawLine(pen_R, shift_x + 0 + x1, shift_y - y1, shift_x + x1 + 0 + dir_x1, shift_y - y1 - dir_y1); //砲管

			// weapon gun			
			if (wea.enable == 1 && wea.counter > 0)
			{
				int R_size1 = wea.diameter;
				x1 = (wea.pos.X) / grid_resolution;
				y1 = (wea.pos.Y + Y_shift) / grid_resolution;
				e1->DrawEllipse(pen_B10, shift_x + x1 - R_size1 / 2, shift_y - y1 - R_size1 / 2,
					R_size1, R_size1);
			}
			// enemy
			if (enemy.point.HP > 0)
			{
				int enemyx1 = (enemy.pos.X) / grid_resolution;
				int enemyy1 = (enemy.pos.Y + Y_shift) / grid_resolution;
				e1->DrawRectangle(pen_BL, shift_x + enemyx1 - R_size / 2, shift_y - enemyy1 - R_size / 2, R_size, R_size);

				int dir_x2 = 40 * cos(enemy.pos.Theta);
				int dir_y2 = 40 * sin(enemy.pos.Theta);
				e1->DrawLine(pen_BL, shift_x + 0 + enemyx1, shift_y - enemyy1, shift_x + enemyx1 + 0 + dir_x2, shift_y - enemyy1 - dir_y2); //砲管
			}
			else
			{
				enemy.enable = 0;
			}
			// enemy weapon
			if (enemy_wea.enable == 1 && enemy_wea.counter > 0 && enemy.enable==1)
			{
				R_size = enemy_wea.diameter;
				x1 = (enemy_wea.pos.X) / grid_resolution;
				y1 = (enemy_wea.pos.Y + Y_shift) / grid_resolution;
				e1->DrawEllipse(pen_BL, shift_x + x1 - R_size / 2, shift_y - y1 - R_size / 2, 20, 20);
			}

		}

		void initialize()
		{
			srand(time(NULL));
			// tank
			tank_profile.pos.X = -80;    //坦克車初始位置
			tank_profile.pos.Y = 80;
			tank_profile.pos.Theta = 1.57;
			tank_profile.point.HP = 100;

			// weapon gun		
			wea.point.HP = 50;   //傷害
			wea.point.SP = 5;    //體力
			wea.range = 100;    //射程
			wea.Velocity = 15;  //速度 12-17
			wea.enable = 0;

			// enemy
			enemy.pos.X = 620;
			enemy.pos.Y = 80;
			enemy.pos.Theta = (rand()%15 - 590) * PI / 180;
			enemy.point.HP = 100;

			// enemy weapon
			enemy_wea.point.HP = 10; 
			enemy_wea.range = 100; 
			enemy_wea.Velocity = 15;
			enemy_wea.enable = 0;
			//enemy_wea.pos.X = enemy.pos.X;
			//enemy_wea.pos.Y = enemy.pos.Y;
			//enemy_wea.V.Vx = enemy_wea.Velocity * cos(enemy.pos.Theta) * dt;
			//enemy_wea.V.Vy = enemy_wea.Velocity * sin(enemy.pos.Theta) * dt;
			//enemy_wea.counter = int((enemy_wea.range / enemy_wea.Velocity) * (1 / dt));
		}

		void Motion_Model(void)
		{
			/*
			if (round == PLAY_ROUND) {
				if (isShot && key) {
					key = 0;
					wea.counter = ;
					wea.enable = 1;

					f(wea.counter);

					isShot = false;
					key = 1;
				}
			}

			else if (round == ENEMY_ROUND) {
				// 幫發射
				isShot = true;
				if (isShot && key) {
					key = 0;
					button3_Click();
				}
				
			}
			*/
			// ----------------------------------------------------------
			// tank's angle
			tank_profile.pos.Theta = tank_profile.pos.Theta + tank_profile.vel.W * dt;

			// weapon
			if (wea.enable == 1 && wea.counter > 0)  //counter與range相關(射程)
			{
				wea.pos.Theta = tank_profile.pos.Theta;//wea.pos.Theta + 45.0 * PI / 180.0; // theta = theta + w * dt
				double launchAngle = wea.pos.Theta; // 發射角度（單位：弧度）

				double vx = wea.Velocity * cos(launchAngle); // X 軸方向速度分量
				double vy = wea.Velocity * sin(launchAngle) - G * wea_time; // Y 軸方向速度分量

				wea.pos.X = wea.pos.X + vx * wea_time;
				wea.pos.Y = wea.pos.Y + wea.Velocity * sin(launchAngle) * wea_time - 0.5 * G * pow(wea_time, 2);

				wea_time += 0.1;
				wea.counter--;
			}

			else
			{
				wea.enable = 0;
			}

			// enemy wea
			
			if ( enemy_wea.counter > 0 && enemy_wea.enable == 1)
			{
				enemy_wea.pos.Theta = enemy.pos.Theta;//wea.pos.Theta + 45.0 * PI / 180.0; // theta = theta + w * dt
				double launchAngle = enemy_wea.pos.Theta; // 發射角度（單位：弧度）

				double vx = enemy_wea.Velocity * cos(launchAngle); // X 軸方向速度分量
				double vy = enemy_wea.Velocity * sin(launchAngle) - G * enemywea_time; // Y 軸方向速度分量

				enemy_wea.pos.X = enemy_wea.pos.X + vx * enemywea_time;
				enemy_wea.pos.Y = enemy_wea.pos.Y + enemy_wea.Velocity * sin(launchAngle) * enemywea_time - 0.5 * G * pow(enemywea_time, 2);

				enemywea_time += 0.1;
				enemy_wea.counter--;
			}

			else
			{
				enemy_wea.enable =	1;

				enemy_wea.pos.X = enemy.pos.X;
				enemy_wea.pos.Y = enemy.pos.Y;
				enemy_wea.V.Vx = enemy_wea.Velocity * cos(4.71 - enemy.pos.Theta) * dt;
				enemy_wea.V.Vy = enemy_wea.Velocity * sin(4.71 - enemy.pos.Theta) * dt;
				enemy_wea.counter = 100;//int((enemy_wea.range / enemy_wea.Velocity) * (1 / dt));

			}
		}
		void collsion_detection(void)
		{
			// between weapon and enemy
			float dis1 = sqrt((wea.pos.X - enemy.pos.X) * (wea.pos.X - enemy.pos.X) + (wea.pos.Y - enemy.pos.Y) * (wea.pos.Y - enemy.pos.Y));
			if (dis1 < 25 && enemy.enable == 1 && wea.enable == 1) {

				enemy.point.HP = enemy.point.HP - wea.point.HP;

				wea.enable = 0; // weapon disappear
				if (enemy.point.HP <= 0)
				{
					enemy.enable = 0; // obstacle disappear
				}
			}
			// between enemy_weapon and tank 
			float dis2 = sqrt((enemy_wea.pos.X - tank_profile.pos.X) * (enemy_wea.pos.X - tank_profile.pos.X) + (enemy_wea.pos.Y - tank_profile.pos.Y) * (enemy_wea.pos.Y - tank_profile.pos.Y));
			if (dis2 < 25  && enemy_wea.enable == 1) {
				tank_profile.point.HP = tank_profile.point.HP - enemy_wea.point.HP;

				enemy_wea.enable = 0; // weapon disappear

				if (enemy.point.HP <= 0)
				{
					enemy.enable = 0; // obstacle disappear
				}
			}
		};

		void text_displayer(void)  //顯示lable的文字
		{


			this->progressBar1->Value = tank_profile.point.HP;
			this->label1->Text = ("HP:" + Convert::ToString(tank_profile.point.HP) + "/100");
			this->progressBar2->Value = enemy.point.HP;
			this->label2->Text = ("HP:" + Convert::ToString(enemy.point.HP) + "/100");
			this->label3->Text = ("Round:" + Convert::ToString(round_count.round1) );
			//this->label4->Text = ("Stage:" + Convert::ToString(round_count.stage) );
			this->label5->Text = ("Time:" + Convert::ToString(round_count.compute_round_time %100 ));

			if (round_count.stage == 0)
			{
				this->label4->Text = "玩家回合";
			}
			if (round_count.stage != 0)
			{
				this->label4->Text = "敵人回合";
			}



		};


		void compute_stage(void)
		{
			if (round_count.stage < 1)
			{
				round_count.stage++;
			}

			else
			{
				round_count.stage = 0;
				round_count.round1++;
			}
		}

		void compute_round(void)
		{
			

			if (round_count.stage == 1)  //敵人攻擊
			{
				
				this->button1->Enabled = true;
				this->button3->Enabled = false;
				this->button4->Enabled = false;
				this->button5->Enabled = false;
				this->button6->Enabled = false;
			}

			else if (round_count.stage == 0)   //坦克攻擊
			{

				
				//enemy_wea.enable = 0;
				this->button1->Enabled = false;
				this->button3->Enabled = true;
				this->button4->Enabled = true;
				this->button5->Enabled = true;
				this->button6->Enabled = true;
			}

			else if (round_count.stage >= 1)     
			{
				round_count.stage == 0;
			}

			

			if (round_count.compute_round_time < 100)  //防止敵人武器一開始射出
			{
				enemy_wea.enable = 0;
			}
			
			else if (/*round_count.compute_round_time % 100 == 0 &&*/ round_count.stage == 1)    //如果回合計時器時間 %100的餘數 =0 (每十秒)  開啟敵人武器
			{
				//compute_stage();
				enemywea_time = 0;
				enemy_wea.enable = 1;
				enemy_wea.pos.X = enemy.pos.X;
				enemy_wea.pos.Y = enemy.pos.Y;
				//tank_profile.point.SP = tank_profile.point.SP - wea.point.SP;
				wea.counter = int((wea.range / wea.Velocity) * (1 / dt)) + 5;
			}


			if (enemy_wea.counter == 0 )
			{
				compute_stage();
			}

		

		}

		



		


		

#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (system_counter == 0)
		{		
			initialize();
		}
		Motion_Model();
		plot_HMI();
		text_displayer();
		collsion_detection();
		compute_round();
		
		system_counter++;
		round_count.compute_round_time+=1;
		
	}
	private:System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		compute_stage();
		enemywea_time = 0;
		enemy_wea.enable = 1;
		enemy_wea.pos.X = enemy.pos.X;
		enemy_wea.pos.Y =  enemy.pos.Y;
		//tank_profile.point.SP = tank_profile.point.SP - wea.point.SP;
		wea.counter = int((wea.range / wea.Velocity) * (1 / dt)) + 5;
		


		
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	compute_stage();
	if (round_count.stage == 0)  //坦克攻擊
	{
		enemy_wea.enable = 0;
		this->button1->Enabled = false;
		this->button3->Enabled = true;
		this->button4->Enabled = true;
		this->button5->Enabled = true;
		this->button6->Enabled = true;
	}

	else if (round_count.stage == 1)   //敵人攻擊
	{
		this->button1->Enabled = true;
		this->button3->Enabled = false;
		this->button4->Enabled = false;
		this->button5->Enabled = false;
		this->button6->Enabled = false;
	}

	else if (round_count.stage >= 1)
	{
		round_count.stage == 0;
	}
	

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	compute_stage();
	wea_time = 0;                     //重製拋物線軌跡的t
	wea.enable = 1;                   //開啟武器的enable
	wea.pos.X = tank_profile.pos.X; //子彈從坦克位置出發
	wea.pos.Y = tank_profile.pos.Y;
	//tank_profile.point.SP = tank_profile.point.SP - wea.point.SP;
	wea.counter = int((wea.range / wea.Velocity) * (1 / dt)) + 50;         //計算子彈飛行的時間
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	tank_profile.vel.W = 0.174 * 5;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	tank_profile.vel.W = -0.174 * 5;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	tank_profile.vel.V = 0;
	tank_profile.vel.W = 0;
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
