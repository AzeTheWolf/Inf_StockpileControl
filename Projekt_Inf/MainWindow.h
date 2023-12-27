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
	private: System::Windows::Forms::ListView^ itemList;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;
	private: System::Windows::Forms::ColumnHeader^ columnHeader5;







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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->newItemNameTB = (gcnew System::Windows::Forms::TextBox());
			this->delItemBtn = (gcnew System::Windows::Forms::Button());
			this->addItemBtn = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->newItemDescTB = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->emptyStoreBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->newStoreNameTB = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->newStoreDescTB = (gcnew System::Windows::Forms::TextBox());
			this->StorageViewTV = (gcnew System::Windows::Forms::TreeView());
			this->itemsTabPage = (gcnew System::Windows::Forms::TabPage());
			this->itemList = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->ErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->windowTabsTC->SuspendLayout();
			this->storageTabPage->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->itemsTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ErrorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// addStoreBtn
			// 
			this->addStoreBtn->Location = System::Drawing::Point(4, 413);
			this->addStoreBtn->Margin = System::Windows::Forms::Padding(2);
			this->addStoreBtn->Name = L"addStoreBtn";
			this->addStoreBtn->Size = System::Drawing::Size(270, 24);
			this->addStoreBtn->TabIndex = 0;
			this->addStoreBtn->Text = L"Dodaj pojemnik";
			this->addStoreBtn->UseVisualStyleBackColor = true;
			this->addStoreBtn->Click += gcnew System::EventHandler(this, &MainWindow::addStoreBtn_Click);
			// 
			// delStoreBtn
			// 
			this->delStoreBtn->Enabled = false;
			this->delStoreBtn->Location = System::Drawing::Point(4, 440);
			this->delStoreBtn->Margin = System::Windows::Forms::Padding(2);
			this->delStoreBtn->Name = L"delStoreBtn";
			this->delStoreBtn->Size = System::Drawing::Size(270, 25);
			this->delStoreBtn->TabIndex = 2;
			this->delStoreBtn->Text = L"Usuñ pojemnik";
			this->delStoreBtn->UseVisualStyleBackColor = true;
			// 
			// windowTabsTC
			// 
			this->windowTabsTC->Controls->Add(this->storageTabPage);
			this->windowTabsTC->Controls->Add(this->itemsTabPage);
			this->windowTabsTC->Location = System::Drawing::Point(4, 27);
			this->windowTabsTC->Margin = System::Windows::Forms::Padding(2);
			this->windowTabsTC->Name = L"windowTabsTC";
			this->windowTabsTC->SelectedIndex = 0;
			this->windowTabsTC->Size = System::Drawing::Size(947, 548);
			this->windowTabsTC->TabIndex = 3;
			// 
			// storageTabPage
			// 
			this->storageTabPage->Controls->Add(this->groupBox2);
			this->storageTabPage->Controls->Add(this->groupBox1);
			this->storageTabPage->Controls->Add(this->StorageViewTV);
			this->storageTabPage->Location = System::Drawing::Point(4, 22);
			this->storageTabPage->Margin = System::Windows::Forms::Padding(2);
			this->storageTabPage->Name = L"storageTabPage";
			this->storageTabPage->Padding = System::Windows::Forms::Padding(2);
			this->storageTabPage->Size = System::Drawing::Size(939, 522);
			this->storageTabPage->TabIndex = 0;
			this->storageTabPage->Text = L"Struktura";
			this->storageTabPage->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->newItemNameTB);
			this->groupBox2->Controls->Add(this->delItemBtn);
			this->groupBox2->Controls->Add(this->addItemBtn);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->newItemDescTB);
			this->groupBox2->Location = System::Drawing::Point(635, 13);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(291, 501);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Zarz¹dzaj przedmiotami";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 24);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Nazwa";
			// 
			// newItemNameTB
			// 
			this->newItemNameTB->Location = System::Drawing::Point(10, 39);
			this->newItemNameTB->Margin = System::Windows::Forms::Padding(2);
			this->newItemNameTB->Name = L"newItemNameTB";
			this->newItemNameTB->Size = System::Drawing::Size(257, 20);
			this->newItemNameTB->TabIndex = 4;
			// 
			// delItemBtn
			// 
			this->delItemBtn->Enabled = false;
			this->delItemBtn->Location = System::Drawing::Point(3, 471);
			this->delItemBtn->Margin = System::Windows::Forms::Padding(2);
			this->delItemBtn->Name = L"delItemBtn";
			this->delItemBtn->Size = System::Drawing::Size(270, 25);
			this->delItemBtn->TabIndex = 2;
			this->delItemBtn->Text = L"Usuñ przedmiot";
			this->delItemBtn->UseVisualStyleBackColor = true;
			// 
			// addItemBtn
			// 
			this->addItemBtn->Location = System::Drawing::Point(3, 444);
			this->addItemBtn->Margin = System::Windows::Forms::Padding(2);
			this->addItemBtn->Name = L"addItemBtn";
			this->addItemBtn->Size = System::Drawing::Size(270, 24);
			this->addItemBtn->TabIndex = 0;
			this->addItemBtn->Text = L"Dodaj przedmiot";
			this->addItemBtn->UseVisualStyleBackColor = true;
			this->addItemBtn->Click += gcnew System::EventHandler(this, &MainWindow::addItemBtn_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 62);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(28, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Opis";
			// 
			// newItemDescTB
			// 
			this->newItemDescTB->Location = System::Drawing::Point(10, 77);
			this->newItemDescTB->Margin = System::Windows::Forms::Padding(2);
			this->newItemDescTB->Multiline = true;
			this->newItemDescTB->Name = L"newItemDescTB";
			this->newItemDescTB->Size = System::Drawing::Size(257, 351);
			this->newItemDescTB->TabIndex = 5;
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
			this->groupBox1->Location = System::Drawing::Point(4, 13);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(291, 501);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Zarz¹dzaj pojemnikami";
			// 
			// emptyStoreBtn
			// 
			this->emptyStoreBtn->Enabled = false;
			this->emptyStoreBtn->Location = System::Drawing::Point(4, 472);
			this->emptyStoreBtn->Margin = System::Windows::Forms::Padding(2);
			this->emptyStoreBtn->Name = L"emptyStoreBtn";
			this->emptyStoreBtn->Size = System::Drawing::Size(270, 25);
			this->emptyStoreBtn->TabIndex = 8;
			this->emptyStoreBtn->Text = L"Opró¿nij pojemnik";
			this->emptyStoreBtn->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 24);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Nazwa";
			// 
			// newStoreNameTB
			// 
			this->newStoreNameTB->Location = System::Drawing::Point(10, 39);
			this->newStoreNameTB->Margin = System::Windows::Forms::Padding(2);
			this->newStoreNameTB->Name = L"newStoreNameTB";
			this->newStoreNameTB->Size = System::Drawing::Size(257, 20);
			this->newStoreNameTB->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 62);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Opis";
			// 
			// newStoreDescTB
			// 
			this->newStoreDescTB->Location = System::Drawing::Point(10, 77);
			this->newStoreDescTB->Margin = System::Windows::Forms::Padding(2);
			this->newStoreDescTB->Multiline = true;
			this->newStoreDescTB->Name = L"newStoreDescTB";
			this->newStoreDescTB->Size = System::Drawing::Size(257, 323);
			this->newStoreDescTB->TabIndex = 5;
			// 
			// StorageViewTV
			// 
			this->ErrorProvider->SetIconAlignment(this->StorageViewTV, System::Windows::Forms::ErrorIconAlignment::TopRight);
			this->StorageViewTV->Location = System::Drawing::Point(300, 13);
			this->StorageViewTV->Margin = System::Windows::Forms::Padding(2);
			this->StorageViewTV->Name = L"StorageViewTV";
			treeNode1->BackColor = System::Drawing::Color::Gainsboro;
			treeNode1->Checked = true;
			treeNode1->ForeColor = System::Drawing::Color::Green;
			treeNode1->Name = L"master";
			treeNode1->Text = L"Magazyn";
			this->StorageViewTV->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode1 });
			this->StorageViewTV->Size = System::Drawing::Size(312, 502);
			this->StorageViewTV->TabIndex = 8;
			// 
			// itemsTabPage
			// 
			this->itemsTabPage->Controls->Add(this->itemList);
			this->itemsTabPage->Location = System::Drawing::Point(4, 22);
			this->itemsTabPage->Margin = System::Windows::Forms::Padding(2);
			this->itemsTabPage->Name = L"itemsTabPage";
			this->itemsTabPage->Size = System::Drawing::Size(939, 522);
			this->itemsTabPage->TabIndex = 1;
			this->itemsTabPage->Text = L"Przedmioty";
			this->itemsTabPage->UseVisualStyleBackColor = true;
			// 
			// itemList
			// 
			this->itemList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5
			});
			this->itemList->FullRowSelect = true;
			this->itemList->HideSelection = false;
			this->itemList->Location = System::Drawing::Point(4, 3);
			this->itemList->MultiSelect = false;
			this->itemList->Name = L"itemList";
			this->itemList->Size = System::Drawing::Size(932, 319);
			this->itemList->TabIndex = 0;
			this->itemList->UseCompatibleStateImageBehavior = false;
			this->itemList->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Nazwa";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Iloœæ";
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Data wa¿noœci";
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Dodano";
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Opis";
			// 
			// ErrorProvider
			// 
			this->ErrorProvider->BlinkRate = 0;
			this->ErrorProvider->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->ErrorProvider->ContainerControl = this;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 585);
			this->Controls->Add(this->windowTabsTC);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->windowTabsTC->ResumeLayout(false);
			this->storageTabPage->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->itemsTabPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ErrorProvider))->EndInit();
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

		TreeNode^ selNode = this->StorageViewTV->SelectedNode; // Isolate selected TreeNode

		// guard: Selected node points at item
		if (selNode->Tag->GetType()->Name == "Item")
		{
			this->ErrorProvider->SetError(this->StorageViewTV,
				L"Nie mo¿na umieœæiæ przedmiotu w innym przedmiocie");

			return;
		}

		if (err) return;

		CStore^ targetStorage = dynamic_cast<CStore^>(selNode->Tag); // Retreive CStore reference from node tag

		// guard: cast failed
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


	private: System::Void addItemBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{

		// Clear errors
		clearErrors();

		bool err = false;
		// guard: name empty
		if (this->newItemNameTB->Lines->Length < 1
			|| System::String::IsNullOrWhiteSpace(this->newItemNameTB->Lines[0]))
		{
			this->ErrorProvider->SetError(this->newItemNameTB,
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

		TreeNode^ selNode = this->StorageViewTV->SelectedNode;

		if (err) return;

		// guard: Selected node points at item
		if (selNode->Tag->GetType()->Name == "Item")
		{
			this->ErrorProvider->SetError(this->StorageViewTV,
				L"Nie mo¿na umieœæiæ przedmiotu w innym przedmiocie");

			return;
		}

		CStore^ targetStorage = dynamic_cast<CStore^>(selNode->Tag);

		// guard: cast failed
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
		Item^ item = gcnew Item(
			this->newItemNameTB->Lines[0],
			System::String::Join(Environment::NewLine, this->newItemDescTB->Lines),
			0
		);

		// Create associated TreeNode
		TreeNode^ node = gcnew TreeNode();
		node->Text = item->getName();
		node->ToolTipText = item->getDescription();
		node->Tag = item;

		// Put in master storage and add to graph
		targetStorage->place(item);
		selNode->Nodes->Add(node);
		this->StorageViewTV->Sort();

		// Add item to Items tab list
		ListViewItem^ listItem = gcnew ListViewItem;
		listItem->Text = item->getName();
		listItem->SubItems->Add(L"");
		listItem->SubItems->Add(L"");
		listItem->SubItems->Add(L"");
		listItem->SubItems->Add(item->getDescription());
		listItem->Tag = item;
		this->itemList->Items->Add(listItem);

		// Clean inputs
		this->newItemNameTB->Clear();
		this->newItemDescTB->Clear();
	}

private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) 
{
	this->StorageViewTV->Nodes[0]->Tag = ProgramState::masterStorage;
}
};
}
