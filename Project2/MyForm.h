#pragma once
#include "RegulatorWindow.h"
#include "SpeedGraphWindow.h"
#include <string>
using namespace std;

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: RegulatorWindow^ RegulatorWindow1;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label22;
	private: SpeedGraphWindow^ SpeedGraphWindow1;

	public:
		MyForm(void)
		{
			InitializeComponent();
			RegulatorWindow1 = gcnew RegulatorWindow(this, 480, 480, 40, 32);
			SpeedGraphWindow1 = gcnew SpeedGraphWindow(this, 420, 200, 600, 350);
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::HScrollBar^ hScrollBar1;





	private: System::Windows::Forms::HScrollBar^ hScrollBar2;
	private: System::Windows::Forms::HScrollBar^ hScrollBar3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ToolStripMenuItem;









	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::HScrollBar^ hScrollBar4;
	private: System::Windows::Forms::HScrollBar^ hScrollBar5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;




	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar2 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar3 = (gcnew System::Windows::Forms::HScrollBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar4 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar5 = (gcnew System::Windows::Forms::HScrollBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->hScrollBar1->LargeChange = 40;
			resources->ApplyResources(this->hScrollBar1, L"hScrollBar1");
			this->hScrollBar1->Maximum = 180;
			this->hScrollBar1->Minimum = -180;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar1_Scroll);
			// 
			// hScrollBar2
			// 
			this->hScrollBar2->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->hScrollBar2, L"hScrollBar2");
			this->hScrollBar2->LargeChange = 18;
			this->hScrollBar2->Maximum = 89;
			this->hScrollBar2->Minimum = -89;
			this->hScrollBar2->Name = L"hScrollBar2";
			this->hScrollBar2->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar2_Scroll);
			// 
			// hScrollBar3
			// 
			this->hScrollBar3->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->hScrollBar3, L"hScrollBar3");
			this->hScrollBar3->Minimum = 10;
			this->hScrollBar3->Name = L"hScrollBar3";
			this->hScrollBar3->Value = 20;
			this->hScrollBar3->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar3_Scroll_1);
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ToolStripMenuItem });
			resources->ApplyResources(this->menuStrip1, L"menuStrip1");
			this->menuStrip1->Name = L"menuStrip1";
			// 
			// ToolStripMenuItem
			// 
			this->ToolStripMenuItem->Name = L"ToolStripMenuItem";
			resources->ApplyResources(this->ToolStripMenuItem, L"ToolStripMenuItem");
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// hScrollBar4
			// 
			this->hScrollBar4->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->hScrollBar4, L"hScrollBar4");
			this->hScrollBar4->LargeChange = 7;
			this->hScrollBar4->Maximum = 70;
			this->hScrollBar4->Name = L"hScrollBar4";
			this->hScrollBar4->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar4_Scroll);
			// 
			// hScrollBar5
			// 
			this->hScrollBar5->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->hScrollBar5, L"hScrollBar5");
			this->hScrollBar5->LargeChange = 16;
			this->hScrollBar5->Maximum = 200;
			this->hScrollBar5->Minimum = 40;
			this->hScrollBar5->Name = L"hScrollBar5";
			this->hScrollBar5->Value = 60;
			this->hScrollBar5->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar5_Scroll);
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->Name = L"label5";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->Name = L"label6";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->Name = L"label8";
			// 
			// label9
			// 
			resources->ApplyResources(this->label9, L"label9");
			this->label9->Name = L"label9";
			// 
			// label10
			// 
			resources->ApplyResources(this->label10, L"label10");
			this->label10->Name = L"label10";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// label11
			// 
			resources->ApplyResources(this->label11, L"label11");
			this->label11->Name = L"label11";
			// 
			// label12
			// 
			resources->ApplyResources(this->label12, L"label12");
			this->label12->Name = L"label12";
			// 
			// label13
			// 
			resources->ApplyResources(this->label13, L"label13");
			this->label13->Name = L"label13";
			// 
			// label14
			// 
			resources->ApplyResources(this->label14, L"label14");
			this->label14->Name = L"label14";
			// 
			// label15
			// 
			resources->ApplyResources(this->label15, L"label15");
			this->label15->Name = L"label15";
			this->label15->Click += gcnew System::EventHandler(this, &MyForm::label15_Click);
			// 
			// label16
			// 
			resources->ApplyResources(this->label16, L"label16");
			this->label16->Name = L"label16";
			// 
			// label17
			// 
			resources->ApplyResources(this->label17, L"label17");
			this->label17->Name = L"label17";
			// 
			// label18
			// 
			resources->ApplyResources(this->label18, L"label18");
			this->label18->Name = L"label18";
			this->label18->Click += gcnew System::EventHandler(this, &MyForm::label18_Click);
			// 
			// label19
			// 
			resources->ApplyResources(this->label19, L"label19");
			this->label19->Name = L"label19";
			this->label19->Click += gcnew System::EventHandler(this, &MyForm::label19_Click);
			// 
			// label20
			// 
			resources->ApplyResources(this->label20, L"label20");
			this->label20->Name = L"label20";
			// 
			// label22
			// 
			resources->ApplyResources(this->label22, L"label22");
			this->label22->Name = L"label22";
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->hScrollBar5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->hScrollBar4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->hScrollBar3);
			this->Controls->Add(this->hScrollBar2);
			this->Controls->Add(this->hScrollBar1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	RegulatorWindow1->time = SpeedGraphWindow1->time * 0.01;
	RegulatorWindow1->Render();
	SpeedGraphWindow1->speed = RegulatorWindow1->speed;
	SpeedGraphWindow1->Render();

	label18->Text = gcnew System::String(to_string(SpeedGraphWindow1->speed).c_str());
	int time = SpeedGraphWindow1->time;
	if (time > MAX_COORD_COUNT) {
		string s1(to_string(time * 0.01 - 10.0)), s2(to_string(time * 0.01));
		s1.erase(s1.length() - 4);
		s2.erase(s2.length() - 4);
		System::String^ str1 = gcnew System::String(s1.c_str());
		System::String^ str2 = gcnew System::String(s2.c_str());
		label17->Text = str1;
		label22->Text = str2;
	}

}
private: System::Void всегдаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void hScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	this->RegulatorWindow1->yaw = e->NewValue;
}
private: System::Void hScrollBar2_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	this->RegulatorWindow1->pitch = e->NewValue;

}
private: System::Void hScrollBar3_Scroll_1(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	this->RegulatorWindow1->distance = int(e->NewValue) * 0.05;
}
private: System::Void hScrollBar4_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	this->RegulatorWindow1->angle = e->NewValue;
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void hScrollBar5_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	this->RegulatorWindow1->speed = e->NewValue * 0.01;
}
private: System::Void label19_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label18_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
