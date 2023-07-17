#pragma once
#include "RegulatorWindow.h"
#include "SpeedGraphWindow.h"

using namespace std;

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label4;

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
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
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
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->Name = L"label6";
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
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
			// 
			// label19
			// 
			resources->ApplyResources(this->label19, L"label19");
			this->label19->Name = L"label19";
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
			// textBox1
			// 
			resources->ApplyResources(this->textBox1, L"textBox1");
			this->textBox1->Name = L"textBox1";
			// 
			// textBox2
			// 
			resources->ApplyResources(this->textBox2, L"textBox2");
			this->textBox2->Name = L"textBox2";
			// 
			// textBox3
			// 
			resources->ApplyResources(this->textBox3, L"textBox3");
			this->textBox3->Name = L"textBox3";
			// 
			// textBox4
			// 
			resources->ApplyResources(this->textBox4, L"textBox4");
			this->textBox4->Name = L"textBox4";
			// 
			// label21
			// 
			resources->ApplyResources(this->label21, L"label21");
			this->label21->Name = L"label21";
			this->label21->MouseLeave += gcnew System::EventHandler(this, &MyForm::label21_MouseLeave);
			this->label21->MouseHover += gcnew System::EventHandler(this, &MyForm::label21_MouseHover);
			// 
			// label23
			// 
			resources->ApplyResources(this->label23, L"label23");
			this->label23->Name = L"label23";
			this->label23->MouseLeave += gcnew System::EventHandler(this, &MyForm::label21_MouseLeave);
			this->label23->MouseHover += gcnew System::EventHandler(this, &MyForm::label23_MouseHover);
			// 
			// label24
			// 
			resources->ApplyResources(this->label24, L"label24");
			this->label24->Name = L"label24";
			this->label24->MouseLeave += gcnew System::EventHandler(this, &MyForm::label21_MouseLeave);
			this->label24->MouseHover += gcnew System::EventHandler(this, &MyForm::label24_MouseHover);
			// 
			// label25
			// 
			resources->ApplyResources(this->label25, L"label25");
			this->label25->Name = L"label25";
			this->label25->MouseLeave += gcnew System::EventHandler(this, &MyForm::label21_MouseLeave);
			this->label25->MouseHover += gcnew System::EventHandler(this, &MyForm::label25_MouseHover);
			// 
			// label26
			// 
			resources->ApplyResources(this->label26, L"label26");
			this->label26->Name = L"label26";
			this->label26->MouseLeave += gcnew System::EventHandler(this, &MyForm::label21_MouseLeave);
			this->label26->MouseHover += gcnew System::EventHandler(this, &MyForm::label26_MouseHover);
			// 
			// label27
			// 
			resources->ApplyResources(this->label27, L"label27");
			this->label27->Name = L"label27";
			this->label27->MouseLeave += gcnew System::EventHandler(this, &MyForm::label21_MouseLeave);
			this->label27->MouseHover += gcnew System::EventHandler(this, &MyForm::label27_MouseHover);
			// 
			// textBox5
			// 
			resources->ApplyResources(this->textBox5, L"textBox5");
			this->textBox5->Name = L"textBox5";
			// 
			// textBox6
			// 
			resources->ApplyResources(this->textBox6, L"textBox6");
			this->textBox6->Name = L"textBox6";
			// 
			// button2
			// 
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label28
			// 
			resources->ApplyResources(this->label28, L"label28");
			this->label28->Name = L"label28";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->hScrollBar3);
			this->Controls->Add(this->hScrollBar2);
			this->Controls->Add(this->hScrollBar1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		RegulatorWindow1->time = SpeedGraphWindow1->time * 0.01;
		RegulatorWindow1->Render();
		if (RegulatorWindow1->IsStopped) SpeedGraphWindow1->IsStopped = TRUE;
		SpeedGraphWindow1->speed = RegulatorWindow1->speed;
		SpeedGraphWindow1->Render();

		label18->Text = Convert::ToString(SpeedGraphWindow1->speed);
		int time = SpeedGraphWindow1->time;
		if (time > MAX_COORD_COUNT) {
			label17->Text = Convert::ToString(time * 0.01 - 10.0);
			label22->Text = Convert::ToString(time * 0.01);
		}

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
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		RegulatorWindow1->fi0 = Convert::ToDouble(this->textBox1->Text);
		RegulatorWindow1->mu0 = Convert::ToDouble(this->textBox2->Text);
		RegulatorWindow1->mu0der = Convert::ToDouble(this->textBox3->Text);
		RegulatorWindow1->Tr_sqr = Convert::ToDouble(this->textBox6->Text);
		RegulatorWindow1->Tk = Convert::ToDouble(this->textBox5->Text);
		RegulatorWindow1->gamma = Convert::ToDouble(this->textBox4->Text);

		SpeedGraphWindow1->shift = RegulatorWindow1->fi0 / RegulatorWindow1->gamma  * 10;

		label16->Text = Convert::ToString( 5 - SpeedGraphWindow1->shift);
		label20->Text = Convert::ToString(-5 - SpeedGraphWindow1->shift);

		SpeedGraphWindow1->IsStopped = FALSE;
		RegulatorWindow1->IsStopped = FALSE;
		label17->Text = "0";
		label22->Text = "10";
		//Close();
		RegulatorWindow1->speed = 1;
		SpeedGraphWindow1->time = 0;
		SpeedGraphWindow1->coordlist.Clear();
		RegulatorWindow1->angle = 0;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//SpeedGraphWindow1->IsStopped = TRUE;
		//RegulatorWindow1->IsStopped = TRUE;
		SpeedGraphWindow1->IsStopped = !SpeedGraphWindow1->IsStopped;
		RegulatorWindow1->IsStopped = !RegulatorWindow1->IsStopped;
	}

private: System::Void label21_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	label4->Visible = FALSE;
}
	private: System::Void label21_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		label4->Text = "Start angle";
		label4->Left = label21->Left - 10;
		label4->Top = label21->Top - 12;
		label4->Visible = TRUE;
	}
private: System::Void label23_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	label4->Text = "Start shift of flap";
	label4->Left = label23->Left - 10;
	label4->Top = label23->Top - 12;
	label4->Visible = TRUE;
}
private: System::Void label24_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	label4->Text = "Start speed of flap";
	label4->Left = label24->Left - 10;
	label4->Top = label24->Top - 12;
	label4->Visible = TRUE;
}
private: System::Void label27_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	label4->Text = "Innertial properties of regulator";
	label4->Left = label27->Left - 10;
	label4->Top = label27->Top - 12;
	label4->Visible = TRUE;
}
private: System::Void label26_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	label4->Text = "Damping properties of regulator";
	label4->Left = label26->Left - 10;
	label4->Top = label26->Top - 12;
	label4->Visible = TRUE;
}
private: System::Void label25_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	label4->Text = "Irregularity of regulator";
	label4->Left = label25->Left - 10;
	label4->Top = label25->Top - 12;
	label4->Visible = TRUE;
}
};
}


////////////////////