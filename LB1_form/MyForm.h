#include "PasswordGenerator.h"

namespace LB1_form {

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
	public:
		bool flag_lower = false, flag_upper = false, flag_digits = false, flag_symbols = false, flag_choose = true;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			setlocale(LC_ALL, "Rus");
			srand(time(0));
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
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(30, 30);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(117, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Маленькие буквы";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(30, 54);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(116, 17);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"Заглавные буквы";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(30, 78);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(58, 17);
			this->checkBox3->TabIndex = 2;
			this->checkBox3->Text = L"Числа";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(30, 102);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(73, 17);
			this->checkBox4->TabIndex = 3;
			this->checkBox4->Text = L"Символы";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox4_CheckedChanged);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(80, 188);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 18);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Ваш пароль";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(80, 150);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Сгенерировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(146, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"P=";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(146, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(20, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"V=";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(146, 103);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(20, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"T=";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(172, 39);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 10;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(172, 68);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 11;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(172, 99);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Name = L"MyForm";
			this->Text = L"LB1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		PasswordGenerator password_gen;
		double P, V, T;
		string pass;
		try {
			P = Convert::ToDouble(textBox1->Text);
			V = Convert::ToDouble(textBox2->Text);
			T = Convert::ToDouble(textBox3->Text);
			pass = password_gen.pass(P, V, T, flag_lower, flag_upper, flag_digits, flag_symbols);
			System::String^ s = gcnew System::String(pass.c_str());
			this->label1->Text = s;
		}
		catch (...){
			this->label1->Text = "error";
		}
		
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox1->Checked)
		{
			flag_lower = true;
		}
		else
		{
			flag_lower = false;
		}
	}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (checkBox2->Checked)
	{
		flag_upper = true;
	}
	else
	{
		flag_upper = false;
	}
}
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (checkBox3->Checked)
	{
		flag_digits = true;
	}
	else
	{
		flag_digits = false;
	}
}
private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (checkBox4->Checked)
	{
		flag_symbols = true;
	}
	else
	{
		flag_symbols = false;
	}
}
};
}
