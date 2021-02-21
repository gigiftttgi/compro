#pragma once
#include "login_admin.h"
#include "showtime.h"

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for home
	/// </summary>
	public ref class home : public System::Windows::Forms::Form
	{
	public:
		home(void)
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
		~home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(222)));
			this->label1->Location = System::Drawing::Point(122, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(568, 69);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to Theater";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(222)));
			this->button1->Location = System::Drawing::Point(343, 225);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 44);
			this->button1->TabIndex = 1;
			this->button1->Text = L"User";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &home::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(222)));
			this->button2->Location = System::Drawing::Point(343, 324);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(131, 42);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Admin";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &home::button2_Click);
			// 
			// home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(832, 513);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"home";
			this->Text = L"home";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		login_admin^ form = gcnew login_admin();
		form->ShowDialog();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		showtime^ form2 = gcnew showtime();
		form2->ShowDialog();
	}
};
}
