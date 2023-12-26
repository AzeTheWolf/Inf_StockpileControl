#pragma once

#include "ProgramState.h"
#include "Item.h"
#include "Compartment.h"

namespace ProjektInf {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ addStoreBtn;
	protected:

	private: System::Windows::Forms::Button^ delStoreBtn;





	private: System::Windows::Forms::TabControl^ windowTabsTC;
	private: System::Windows::Forms::TabPage^ storageTabPage;

	private: System::Windows::Forms::TextBox^ newStoreNameTB;
	private: System::Windows::Forms::TextBox^ newStoreDescTB;







	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::ErrorProvider^ ErrorProvider;
	private: System::Windows::Forms::TreeView^ StorageViewTV;
	private: System::Windows::Forms::TabPage^ itemsTabPage;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ newItemNameTB;
	private: System::Windows::Forms::Button^ delItemBtn;


	private: System::Windows::Forms::Button^ addItemBtn;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ newItemDescTB;
	private: System::Windows::Forms::Button^ emptyStoreBtn;






	private: System::ComponentModel::IContainer^ components;




	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::TreeNode^ treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"Magazyn"));
			this->addStoreBtn = (gcnew System::Windows::Forms::Button());
			this->delStoreBtn = (gcnew System::Windows::Forms::Button());
			this->windowTabsTC = (gcnew System::Windows::Forms::TabControl());
			this->storageTabPage = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->newStoreNameTB = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->newStoreDescTB = (gcnew System::Windows::Forms::TextBox());
			this->StorageViewTV = (gcnew System::Windows::Forms::TreeView());
			this->itemsTabPage = (gcnew System::Windows::Forms::TabPage());
			this->ErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->newItemNameTB = (gcnew System::Windows::Forms::TextBox());
			this->delItemBtn = (gcnew System::Windows::Forms::Button());
			this->addItemBtn = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->newItemDescTB = (gcnew System::Windows::Forms::TextBox());
			this->emptyStoreBtn = (gcnew System::Windows::Forms::Button());
			this->windowTabsTC->SuspendLayout();
			this->storageTabPage->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ErrorProvider))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// addStoreBtn
			// 
			this->addStoreBtn->Location = System::Drawing::Point(6, 508);
			this->addStoreBtn->Name = L"addStoreBtn";
			this->addStoreBtn->Size = System::Drawing::Size(360, 29);
			this->addStoreBtn->TabIndex = 0;
			this->addStoreBtn->Text = L"Dodaj pojemnik";
			this->addStoreBtn->UseVisualStyleBackColor = true;
			this->addStoreBtn->Click += gcnew System::EventHandler(this, &MainWindow::addStoreBtn_Click);
			// 
			// delStoreBtn
			// 
			this->delStoreBtn->Enabled = false;
			this->delStoreBtn->Location = System::Drawing::Point(6, 542);
			this->delStoreBtn->Name = L"delStoreBtn";
			this->delStoreBtn->Size = System::Drawing::Size(360, 31);
			this->delStoreBtn->TabIndex = 2;
			this->delStoreBtn->Text = L"Usuñ pojemnik";
			this->delStoreBtn->UseVisualStyleBackColor = true;
			// 
			// windowTabsTC
			// 
			this->windowTabsTC->Controls->Add(this->storageTabPage);
			this->windowTabsTC->Controls->Add(this->itemsTabPage);
			this->windowTabsTC->Location = System::Drawing::Point(5, 33);
			this->windowTabsTC->Name = L"windowTabsTC";
			this->windowTabsTC->SelectedIndex = 0;
			this->windowTabsTC->Size = System::Drawing::Size(1263, 675);
			this->windowTabsTC->TabIndex = 3;
			// 
			// storageTabPage
			// 
			this->storageTabPage->Controls->Add(this->groupBox2);
			this->storageTabPage->Controls->Add(this->groupBox1);
			this->storageTabPage->Controls->Add(this->StorageViewTV);
			this->storageTabPage->Location = System::Drawing::Point(4, 25);
			this->storageTabPage->Name = L"storageTabPage";
			this->storageTabPage->Padding = System::Windows::Forms::Padding(3);
			this->storageTabPage->Size = System::Drawing::Size(1255, 646);
			this->storageTabPage->TabIndex = 0;
			this->storageTabPage->Text = L"Struktura";
			this->storageTabPage->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->emptyStoreBtn);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->newStoreNameTB);
			this->groupBox1->Controls->Add(this->delStoreBtn);
			this->groupBox1->Controls->Add(this->addStoreBtn);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->newStoreDescTB);
			this->groupBox1->Location = System::Drawing::Point(6, 16);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(388, 617);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Zarz¹dzaj pojemnikami";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 16);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Nazwa";
			// 
			// newStoreNameTB
			// 
			this->newStoreNameTB->Location = System::Drawing::Point(13, 48);
			this->newStoreNameTB->Name = L"newStoreNameTB";
			this->newStoreNameTB->Size = System::Drawing::Size(341, 22);
			this->newStoreNameTB->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Opis";
			// 
			// newStoreDescTB
			// 
			this->newStoreDescTB->Location = System::Drawing::Point(14, 95);
			this->newStoreDescTB->Multiline = true;
			this->newStoreDescTB->Name = L"newStoreDescTB";
			this->newStoreDescTB->Size = System::Drawing::Size(341, 397);
			this->newStoreDescTB->TabIndex = 5;
			// 
			// StorageViewTV
			// 
			this->ErrorProvider->SetIconAlignment(this->StorageViewTV, System::Windows::Forms::ErrorIconAlignment::TopRight);
			this->StorageViewTV->Location = System::Drawing::Point(400, 16);
			this->StorageViewTV->Name = L"StorageViewTV";
			treeNode1->BackColor = System::Drawing::Color::Gainsboro;
			treeNode1->ForeColor = System::Drawing::Color::Green;
			treeNode1->Name = L"master";
			treeNode1->Text = L"Magazyn";
			this->StorageViewTV->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode1 });
			this->StorageViewTV->Size = System::Drawing::Size(414, 617);
			this->StorageViewTV->TabIndex = 8;
			// 
			// itemsTabPage
			// 
			this->itemsTabPage->Location = System::Drawing::Point(4, 25);
			this->itemsTabPage->Name = L"itemsTabPage";
			this->itemsTabPage->Size = System::Drawing::Size(1255, 646);
			this->itemsTabPage->TabIndex = 1;
			this->itemsTabPage->Text = L"Przedmioty";
			this->itemsTabPage->UseVisualStyleBackColor = true;
			// 
			// ErrorProvider
			// 
			this->ErrorProvider->BlinkRate = 0;
			this->ErrorProvider->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->ErrorProvider->ContainerControl = this;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->newItemNameTB);
			this->groupBox2->Controls->Add(this->delItemBtn);
			this->groupBox2->Controls->Add(this->addItemBtn);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->newItemDescTB);
			this->groupBox2->Location = System::Drawing::Point(847, 16);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(388, 617);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Zarz¹dzaj przedmiotami";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Nazwa";
			// 
			// newItemNameTB
			// 
			this->newItemNameTB->Location = System::Drawing::Point(13, 48);
			this->newItemNameTB->Name = L"newItemNameTB";
			this->newItemNameTB->Size = System::Drawing::Size(341, 22);
			this->newItemNameTB->TabIndex = 4;
			// 
			// delItemBtn
			// 
			this->delItemBtn->Enabled = false;
			this->delItemBtn->Location = System::Drawing::Point(4, 580);
			this->delItemBtn->Name = L"delItemBtn";
			this->delItemBtn->Size = System::Drawing::Size(360, 31);
			this->delItemBtn->TabIndex = 2;
			this->delItemBtn->Text = L"Usuñ przedmiot";
			this->delItemBtn->UseVisualStyleBackColor = true;
			// 
			// addItemBtn
			// 
			this->addItemBtn->Location = System::Drawing::Point(4, 546);
			this->addItemBtn->Name = L"addItemBtn";
			this->addItemBtn->Size = System::Drawing::Size(360, 29);
			this->addItemBtn->TabIndex = 0;
			this->addItemBtn->Text = L"Dodaj przedmiot";
			this->addItemBtn->UseVisualStyleBackColor = true;
			this->addItemBtn->Click += gcnew System::EventHandler(this, &MainWindow::addItemBtn_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 76);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Opis";
			// 
			// newItemDescTB
			// 
			this->newItemDescTB->Location = System::Drawing::Point(14, 95);
			this->newItemDescTB->Multiline = true;
			this->newItemDescTB->Name = L"newItemDescTB";
			this->newItemDescTB->Size = System::Drawing::Size(341, 431);
			this->newItemDescTB->TabIndex = 5;
			// 
			// emptyStoreBtn
			// 
			this->emptyStoreBtn->Enabled = false;
			this->emptyStoreBtn->Location = System::Drawing::Point(6, 581);
			this->emptyStoreBtn->Name = L"emptyStoreBtn";
			this->emptyStoreBtn->Size = System::Drawing::Size(360, 31);
			this->emptyStoreBtn->TabIndex = 8;
			this->emptyStoreBtn->Text = L"Opró¿nij pojemnik";
			this->emptyStoreBtn->UseVisualStyleBackColor = true;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->windowTabsTC);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->windowTabsTC->ResumeLayout(false);
			this->storageTabPage->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ErrorProvider))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		/**
		* Clean all errors
		*/
		private: void clearErrors()
		{
			this->ErrorProvider->SetError(this->newStoreNameTB, nullptr);
			this->ErrorProvider->SetError(this->StorageViewTV, nullptr);
			this->ErrorProvider->SetError(this->newItemNameTB, nullptr);
		}


		/**
		* Add Store button clicked
		*/
	private: System::Void addStoreBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Clear errors
		clearErrors();

		bool err = false;
		// guard: name empty
		if (this->newStoreNameTB->Lines->Length < 1
			|| System::String::IsNullOrWhiteSpace(this->newStoreNameTB->Lines[0]))
		{
			this->ErrorProvider->SetError(this->newStoreNameTB,
				L"To pole nie mo¿e byæ puste");
			err = true;
		}

		// guard: target not selected
		if (this->StorageViewTV->SelectedNode == nullptr)
		{
			this->ErrorProvider->SetError(this->StorageViewTV,
				L"Wybierz, gdzie umieœciæ pojemnik");

			err = true;
		}

		if (err) return;

		TreeNode^ selNode = this->StorageViewTV->SelectedNode;


		CStore^ targetStorage = dynamic_cast<CStore^>(selNode->Tag);

		if (targetStorage == nullptr)
		{
			System::String^ errMsg = L"Aplikacja napotka³a niespodziewany problem";
			System::String^ cap = L"Wybrany element nie zawiera prawid³owego wska¿nika";

			auto errbox = MessageBox::Show(
				errMsg, cap,
				MessageBoxButtons::OKCancel,
				MessageBoxIcon::Error
			);
			if (errbox == System::Windows::Forms::DialogResult::OK)
			{
				return;
			}
			else
			{
				Application::Exit();
			}
		}

		// Create new Container
		Compartment^ item = gcnew Compartment(
			this->newStoreNameTB->Lines[0],
			System::String::Join(Environment::NewLine, this->newStoreDescTB->Lines)
		);

		// Create associated TreeNode
		TreeNode^ node = gcnew TreeNode();
		node->Text = item->getName();
		node->ToolTipText = item->getDescription();
		node->Tag = item;
		node->BackColor = System::Drawing::Color::Gainsboro;
		node->ForeColor = System::Drawing::Color::Green;

		// Put in master storage and add to graph
		targetStorage->place(item);
		selNode->Nodes->Add(node);
		this->StorageViewTV->Sort();

		// Clean inputs
		this->newStoreNameTB->Clear();
		this->newStoreDescTB->Clear();
	}


private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) 
{
	this->StorageViewTV->Nodes[0]->Tag = ProgramState::masterStorage;
}
};
}
