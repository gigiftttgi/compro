#pragma once
#include "admin_menu.h"
namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for login_admin
	/// </summary>
	public ref class login_admin : public System::Windows::Forms::Form
	{
	public:
		login_admin(void)
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
		~login_admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(222)));
			this->label1->Location = System::Drawing::Point(143, 201);
			this->label1->Margin = System::Windows::Forms::Padding(9, 0, 9, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(180, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Password :";
			this->label1->Click += gcnew System::EventHandler(this, &login_admin::label1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(222)));
			this->button1->Location = System::Drawing::Point(324, 290);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 47);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &login_admin::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(345, 192);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(320, 53);
			this->textBox1->TabIndex = 2;
			this->textBox1->UseSystemPasswordChar = true;
			// 
			// login_admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(23, 46);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(832, 513);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(222)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(9);
			this->Name = L"login_admin";
			this->Text = L"login_admin";
			this->Load += gcnew System::EventHandler(this, &login_admin::login_admin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int count = 0;
		if (textBox1->Text == "keypass") {
			this->Hide();
			admin_menu^ form = gcnew admin_menu();
			form->ShowDialog();
		}
		else {
			MessageBox::Show("Incorrect Password"), MessageBoxButtons::OK, MessageBoxIcon::Error;
			count = count + 1;
			if (count == 5) {
				MessageBox::Show("System lock!!! Please wait and try again"), MessageBoxIcon::Error, MessageBoxButtons::OK;
				Application::Exit();
			}
		}
	}
	private: System::Void login_admin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
