#pragma once

#include "ProgramState.h"
#include "Item.h"
#include "Compartment.h"
#include "ComponentMutator.h"
#include "DataReadWrite.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Program {

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
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ magazynTSMI;

	private: System::Windows::Forms::ToolStripMenuItem^ emptyMainTSMI;
	private: System::Windows::Forms::Button^ findItemBtn;
	private: System::Windows::Forms::NumericUpDown^ itemQuantityNUD;
	private: System::Windows::Forms::Button^ setQuantityBtn;
	private: System::Windows::Forms::Button^ setItemExpiryBtn;
	private: System::Windows::Forms::DateTimePicker^ itemExpiryDTP;
	private: System::Windows::Forms::Button^ delItemExpiryBtn;
	private: System::Windows::Forms::Button^ setNotifQtyBtn;
	private: System::Windows::Forms::NumericUpDown^ alertQtyNUD;
	private: System::Windows::Forms::ColumnHeader^ columnHeader6;
	private: System::Windows::Forms::ToolStripMenuItem^ refreshStoreTSMI;
	private: System::Windows::Forms::ToolStripMenuItem^ itemTSMI;


	private: System::Windows::Forms::ToolStripMenuItem^ odœwie¿ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ delAllItemsTSMI;
	private: System::Windows::Forms::ToolStripMenuItem^ fileTSMI;
	private: System::Windows::Forms::ToolStripMenuItem^ saveTSMI;
	private: System::Windows::Forms::ToolStripMenuItem^ openTSMI;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsTSMI;














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
			this->setNotifQtyBtn = (gcnew System::Windows::Forms::Button());
			this->alertQtyNUD = (gcnew System::Windows::Forms::NumericUpDown());
			this->delItemExpiryBtn = (gcnew System::Windows::Forms::Button());
			this->setItemExpiryBtn = (gcnew System::Windows::Forms::Button());
			this->itemExpiryDTP = (gcnew System::Windows::Forms::DateTimePicker());
			this->setQuantityBtn = (gcnew System::Windows::Forms::Button());
			this->itemQuantityNUD = (gcnew System::Windows::Forms::NumericUpDown());
			this->findItemBtn = (gcnew System::Windows::Forms::Button());
			this->itemList = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->ErrorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->magazynTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->emptyMainTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->refreshStoreTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->itemTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->odœwie¿ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->delAllItemsTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->windowTabsTC->SuspendLayout();
			this->storageTabPage->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->itemsTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->alertQtyNUD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->itemQuantityNUD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ErrorProvider))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// addStoreBtn
			// 
			this->addStoreBtn->Location = System::Drawing::Point(5, 508);
			this->addStoreBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addStoreBtn->Name = L"addStoreBtn";
			this->addStoreBtn->Size = System::Drawing::Size(360, 30);
			this->addStoreBtn->TabIndex = 0;
			this->addStoreBtn->Text = L"Dodaj pojemnik";
			this->addStoreBtn->UseVisualStyleBackColor = true;
			this->addStoreBtn->Click += gcnew System::EventHandler(this, &MainWindow::addStoreBtn_Click);
			// 
			// delStoreBtn
			// 
			this->delStoreBtn->Enabled = false;
			this->delStoreBtn->Location = System::Drawing::Point(5, 542);
			this->delStoreBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->delStoreBtn->Name = L"delStoreBtn";
			this->delStoreBtn->Size = System::Drawing::Size(360, 31);
			this->delStoreBtn->TabIndex = 2;
			this->delStoreBtn->Text = L"Usuñ pojemnik";
			this->delStoreBtn->UseVisualStyleBackColor = true;
			this->delStoreBtn->Click += gcnew System::EventHandler(this, &MainWindow::delStoreBtn_Click);
			// 
			// windowTabsTC
			// 
			this->windowTabsTC->Controls->Add(this->storageTabPage);
			this->windowTabsTC->Controls->Add(this->itemsTabPage);
			this->windowTabsTC->Location = System::Drawing::Point(5, 33);
			this->windowTabsTC->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->windowTabsTC->Name = L"windowTabsTC";
			this->windowTabsTC->SelectedIndex = 0;
			this->windowTabsTC->Size = System::Drawing::Size(1263, 674);
			this->windowTabsTC->TabIndex = 3;
			// 
			// storageTabPage
			// 
			this->storageTabPage->Controls->Add(this->groupBox2);
			this->storageTabPage->Controls->Add(this->groupBox1);
			this->storageTabPage->Controls->Add(this->StorageViewTV);
			this->storageTabPage->Location = System::Drawing::Point(4, 25);
			this->storageTabPage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->storageTabPage->Name = L"storageTabPage";
			this->storageTabPage->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->storageTabPage->Size = System::Drawing::Size(1255, 645);
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
			this->groupBox2->Location = System::Drawing::Point(847, 16);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->newItemNameTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->newItemNameTB->Name = L"newItemNameTB";
			this->newItemNameTB->Size = System::Drawing::Size(341, 22);
			this->newItemNameTB->TabIndex = 4;
			// 
			// delItemBtn
			// 
			this->delItemBtn->Enabled = false;
			this->delItemBtn->Location = System::Drawing::Point(4, 580);
			this->delItemBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->delItemBtn->Name = L"delItemBtn";
			this->delItemBtn->Size = System::Drawing::Size(360, 31);
			this->delItemBtn->TabIndex = 2;
			this->delItemBtn->Text = L"Usuñ przedmiot";
			this->delItemBtn->UseVisualStyleBackColor = true;
			this->delItemBtn->Click += gcnew System::EventHandler(this, &MainWindow::delItemBtn_Click);
			// 
			// addItemBtn
			// 
			this->addItemBtn->Location = System::Drawing::Point(4, 546);
			this->addItemBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addItemBtn->Name = L"addItemBtn";
			this->addItemBtn->Size = System::Drawing::Size(360, 30);
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
			this->newItemDescTB->Location = System::Drawing::Point(13, 95);
			this->newItemDescTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->newItemDescTB->Multiline = true;
			this->newItemDescTB->Name = L"newItemDescTB";
			this->newItemDescTB->Size = System::Drawing::Size(341, 431);
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
			this->groupBox1->Location = System::Drawing::Point(5, 16);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(388, 617);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Zarz¹dzaj pojemnikami";
			// 
			// emptyStoreBtn
			// 
			this->emptyStoreBtn->Enabled = false;
			this->emptyStoreBtn->Location = System::Drawing::Point(5, 581);
			this->emptyStoreBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->emptyStoreBtn->Name = L"emptyStoreBtn";
			this->emptyStoreBtn->Size = System::Drawing::Size(360, 31);
			this->emptyStoreBtn->TabIndex = 8;
			this->emptyStoreBtn->Text = L"Opró¿nij pojemnik";
			this->emptyStoreBtn->UseVisualStyleBackColor = true;
			this->emptyStoreBtn->Click += gcnew System::EventHandler(this, &MainWindow::emptyStoreBtn_Click);
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
			this->newStoreNameTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->newStoreDescTB->Location = System::Drawing::Point(13, 95);
			this->newStoreDescTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->newStoreDescTB->Multiline = true;
			this->newStoreDescTB->Name = L"newStoreDescTB";
			this->newStoreDescTB->Size = System::Drawing::Size(341, 397);
			this->newStoreDescTB->TabIndex = 5;
			// 
			// StorageViewTV
			// 
			this->ErrorProvider->SetIconAlignment(this->StorageViewTV, System::Windows::Forms::ErrorIconAlignment::TopRight);
			this->StorageViewTV->Location = System::Drawing::Point(400, 16);
			this->StorageViewTV->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->StorageViewTV->Name = L"StorageViewTV";
			treeNode1->BackColor = System::Drawing::Color::Gainsboro;
			treeNode1->Checked = true;
			treeNode1->ForeColor = System::Drawing::Color::Green;
			treeNode1->Name = L"master";
			treeNode1->Text = L"Magazyn";
			this->StorageViewTV->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode1 });
			this->StorageViewTV->Size = System::Drawing::Size(415, 617);
			this->StorageViewTV->TabIndex = 8;
			this->StorageViewTV->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainWindow::StorageViewTV_AfterSelect);
			// 
			// itemsTabPage
			// 
			this->itemsTabPage->Controls->Add(this->setNotifQtyBtn);
			this->itemsTabPage->Controls->Add(this->alertQtyNUD);
			this->itemsTabPage->Controls->Add(this->delItemExpiryBtn);
			this->itemsTabPage->Controls->Add(this->setItemExpiryBtn);
			this->itemsTabPage->Controls->Add(this->itemExpiryDTP);
			this->itemsTabPage->Controls->Add(this->setQuantityBtn);
			this->itemsTabPage->Controls->Add(this->itemQuantityNUD);
			this->itemsTabPage->Controls->Add(this->findItemBtn);
			this->itemsTabPage->Controls->Add(this->itemList);
			this->itemsTabPage->Location = System::Drawing::Point(4, 25);
			this->itemsTabPage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->itemsTabPage->Name = L"itemsTabPage";
			this->itemsTabPage->Size = System::Drawing::Size(1255, 645);
			this->itemsTabPage->TabIndex = 1;
			this->itemsTabPage->Text = L"Przedmioty";
			this->itemsTabPage->UseVisualStyleBackColor = true;
			// 
			// setNotifQtyBtn
			// 
			this->setNotifQtyBtn->Enabled = false;
			this->setNotifQtyBtn->Location = System::Drawing::Point(145, 508);
			this->setNotifQtyBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->setNotifQtyBtn->Name = L"setNotifQtyBtn";
			this->setNotifQtyBtn->Size = System::Drawing::Size(240, 46);
			this->setNotifQtyBtn->TabIndex = 8;
			this->setNotifQtyBtn->Text = L"Ustaw poziom powiadomienia";
			this->setNotifQtyBtn->UseVisualStyleBackColor = true;
			this->setNotifQtyBtn->Click += gcnew System::EventHandler(this, &MainWindow::setNotifQtyBtn_Click);
			// 
			// alertQtyNUD
			// 
			this->alertQtyNUD->Location = System::Drawing::Point(13, 518);
			this->alertQtyNUD->Margin = System::Windows::Forms::Padding(4);
			this->alertQtyNUD->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65565, 0, 0, 0 });
			this->alertQtyNUD->Name = L"alertQtyNUD";
			this->alertQtyNUD->Size = System::Drawing::Size(120, 22);
			this->alertQtyNUD->TabIndex = 7;
			// 
			// delItemExpiryBtn
			// 
			this->delItemExpiryBtn->Enabled = false;
			this->delItemExpiryBtn->Location = System::Drawing::Point(268, 454);
			this->delItemExpiryBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->delItemExpiryBtn->Name = L"delItemExpiryBtn";
			this->delItemExpiryBtn->Size = System::Drawing::Size(117, 46);
			this->delItemExpiryBtn->TabIndex = 6;
			this->delItemExpiryBtn->Text = L"Usuñ datê wa¿noœci";
			this->delItemExpiryBtn->UseVisualStyleBackColor = true;
			this->delItemExpiryBtn->Click += gcnew System::EventHandler(this, &MainWindow::delItemExpiryBtn_Click);
			// 
			// setItemExpiryBtn
			// 
			this->setItemExpiryBtn->Enabled = false;
			this->setItemExpiryBtn->Location = System::Drawing::Point(145, 454);
			this->setItemExpiryBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->setItemExpiryBtn->Name = L"setItemExpiryBtn";
			this->setItemExpiryBtn->Size = System::Drawing::Size(117, 46);
			this->setItemExpiryBtn->TabIndex = 5;
			this->setItemExpiryBtn->Text = L"Ustaw datê wa¿noœci";
			this->setItemExpiryBtn->UseVisualStyleBackColor = true;
			this->setItemExpiryBtn->Click += gcnew System::EventHandler(this, &MainWindow::setItemExpiryBtn_Click);
			// 
			// itemExpiryDTP
			// 
			this->itemExpiryDTP->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->itemExpiryDTP->Location = System::Drawing::Point(13, 465);
			this->itemExpiryDTP->Margin = System::Windows::Forms::Padding(4);
			this->itemExpiryDTP->MinDate = System::DateTime(2024, 1, 1, 0, 0, 0, 0);
			this->itemExpiryDTP->Name = L"itemExpiryDTP";
			this->itemExpiryDTP->Size = System::Drawing::Size(119, 22);
			this->itemExpiryDTP->TabIndex = 4;
			// 
			// setQuantityBtn
			// 
			this->setQuantityBtn->Enabled = false;
			this->setQuantityBtn->Location = System::Drawing::Point(145, 410);
			this->setQuantityBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->setQuantityBtn->Name = L"setQuantityBtn";
			this->setQuantityBtn->Size = System::Drawing::Size(240, 33);
			this->setQuantityBtn->TabIndex = 3;
			this->setQuantityBtn->Text = L"Ustaw iloœæ";
			this->setQuantityBtn->UseVisualStyleBackColor = true;
			this->setQuantityBtn->Click += gcnew System::EventHandler(this, &MainWindow::setQuantityBtn_Click);
			// 
			// itemQuantityNUD
			// 
			this->itemQuantityNUD->Location = System::Drawing::Point(13, 415);
			this->itemQuantityNUD->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->itemQuantityNUD->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
			this->itemQuantityNUD->Name = L"itemQuantityNUD";
			this->itemQuantityNUD->Size = System::Drawing::Size(120, 22);
			this->itemQuantityNUD->TabIndex = 2;
			// 
			// findItemBtn
			// 
			this->findItemBtn->Enabled = false;
			this->findItemBtn->Location = System::Drawing::Point(1112, 402);
			this->findItemBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->findItemBtn->Name = L"findItemBtn";
			this->findItemBtn->Size = System::Drawing::Size(133, 34);
			this->findItemBtn->TabIndex = 1;
			this->findItemBtn->Text = L"ZnajdŸ przedmiot";
			this->findItemBtn->UseVisualStyleBackColor = true;
			this->findItemBtn->Click += gcnew System::EventHandler(this, &MainWindow::findItemBtn_Click);
			// 
			// itemList
			// 
			this->itemList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6
			});
			this->itemList->FullRowSelect = true;
			this->itemList->HideSelection = false;
			this->itemList->Location = System::Drawing::Point(5, 4);
			this->itemList->Margin = System::Windows::Forms::Padding(4);
			this->itemList->MultiSelect = false;
			this->itemList->Name = L"itemList";
			this->itemList->Size = System::Drawing::Size(1241, 392);
			this->itemList->TabIndex = 0;
			this->itemList->UseCompatibleStateImageBehavior = false;
			this->itemList->View = System::Windows::Forms::View::Details;
			this->itemList->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::itemList_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Nazwa";
			this->columnHeader1->Width = 120;
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
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Ostrze¿ gdy";
			this->columnHeader6->Width = 85;
			// 
			// ErrorProvider
			// 
			this->ErrorProvider->BlinkRate = 0;
			this->ErrorProvider->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->ErrorProvider->ContainerControl = this;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileTSMI, this->magazynTSMI,
					this->itemTSMI
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1280, 28);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileTSMI
			// 
			this->fileTSMI->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openTSMI, this->saveTSMI,
					this->saveAsTSMI
			});
			this->fileTSMI->Name = L"fileTSMI";
			this->fileTSMI->Size = System::Drawing::Size(46, 24);
			this->fileTSMI->Text = L"Plik";
			// 
			// openTSMI
			// 
			this->openTSMI->Name = L"openTSMI";
			this->openTSMI->Size = System::Drawing::Size(168, 26);
			this->openTSMI->Text = L"Otwórz";
			this->openTSMI->Click += gcnew System::EventHandler(this, &MainWindow::openTSMI_Click);
			// 
			// saveTSMI
			// 
			this->saveTSMI->Name = L"saveTSMI";
			this->saveTSMI->Size = System::Drawing::Size(168, 26);
			this->saveTSMI->Text = L"Zapisz";
			this->saveTSMI->Click += gcnew System::EventHandler(this, &MainWindow::saveTSMI_Click);
			// 
			// saveAsTSMI
			// 
			this->saveAsTSMI->Name = L"saveAsTSMI";
			this->saveAsTSMI->Size = System::Drawing::Size(168, 26);
			this->saveAsTSMI->Text = L"Zapisz Jako";
			this->saveAsTSMI->Click += gcnew System::EventHandler(this, &MainWindow::saveAsTSMI_Click);
			// 
			// magazynTSMI
			// 
			this->magazynTSMI->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->emptyMainTSMI,
					this->refreshStoreTSMI
			});
			this->magazynTSMI->Name = L"magazynTSMI";
			this->magazynTSMI->Size = System::Drawing::Size(83, 24);
			this->magazynTSMI->Text = L"Magazyn";
			// 
			// emptyMainTSMI
			// 
			this->emptyMainTSMI->Name = L"emptyMainTSMI";
			this->emptyMainTSMI->Size = System::Drawing::Size(265, 26);
			this->emptyMainTSMI->Text = L"Opró¿nij magazyn g³ówny";
			this->emptyMainTSMI->Click += gcnew System::EventHandler(this, &MainWindow::emptyMainTSMI_Click);
			// 
			// refreshStoreTSMI
			// 
			this->refreshStoreTSMI->Name = L"refreshStoreTSMI";
			this->refreshStoreTSMI->Size = System::Drawing::Size(265, 26);
			this->refreshStoreTSMI->Text = L"Odœwie¿";
			this->refreshStoreTSMI->Click += gcnew System::EventHandler(this, &MainWindow::refreshStoreTSMI_Click);
			// 
			// itemTSMI
			// 
			this->itemTSMI->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->odœwie¿ToolStripMenuItem1,
					this->delAllItemsTSMI
			});
			this->itemTSMI->Name = L"itemTSMI";
			this->itemTSMI->Size = System::Drawing::Size(91, 24);
			this->itemTSMI->Text = L"Przedmiot";
			// 
			// odœwie¿ToolStripMenuItem1
			// 
			this->odœwie¿ToolStripMenuItem1->Name = L"odœwie¿ToolStripMenuItem1";
			this->odœwie¿ToolStripMenuItem1->Size = System::Drawing::Size(189, 26);
			this->odœwie¿ToolStripMenuItem1->Text = L"Odœwie¿";
			this->odœwie¿ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::odœwie¿ToolStripMenuItem1_Click);
			// 
			// delAllItemsTSMI
			// 
			this->delAllItemsTSMI->Name = L"delAllItemsTSMI";
			this->delAllItemsTSMI->Size = System::Drawing::Size(189, 26);
			this->delAllItemsTSMI->Text = L"Usuñ wszystkie";
			this->delAllItemsTSMI->Click += gcnew System::EventHandler(this, &MainWindow::delAllItemsTSMI_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"xml";
			this->saveFileDialog1->Filter = L"*.xml|";
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"xml";
			this->openFileDialog->Filter = L"*.xml|";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->windowTabsTC);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1298, 767);
			this->MinimumSize = System::Drawing::Size(1298, 767);
			this->Name = L"MainWindow";
			this->Text = L"Magazyn";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->windowTabsTC->ResumeLayout(false);
			this->storageTabPage->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->itemsTabPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->alertQtyNUD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->itemQuantityNUD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ErrorProvider))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

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

		private: void lockStructTabBtns()
		{
			this->delItemBtn->Enabled = false;
			this->delStoreBtn->Enabled = false;
			this->emptyStoreBtn->Enabled = false;
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

		if (err) return;

		// guard: Selected node points at item
		if (selNode->Tag->GetType()->Name == "Item")
		{
			this->ErrorProvider->SetError(this->StorageViewTV,
				L"Nie mo¿na umieœæiæ przedmiotu w innym przedmiocie");

			return;
		}

		CStore^ targetStorage = dynamic_cast<CStore^>(selNode->Tag); // Retreive CStore reference from node tag

		// guard: cast failed
		if (targetStorage == nullptr)
		{
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wska¿nika");
			return;
		}

		// Create new Container
		Compartment^ item = gcnew Compartment(
			this->newStoreNameTB->Lines[0],
			System::String::Join(Environment::NewLine, this->newStoreDescTB->Lines)
		);

		// Create associated TreeNode
		TreeNode^ node = ComponentMutator::createTreeNode(item, true);

		

		// Put in master storage and add to graph
		targetStorage->place(item);
		selNode->Nodes->Add(node);
		this->StorageViewTV->Sort();

		// Clean inputs
		this->newStoreNameTB->Clear();
		this->newStoreDescTB->Clear();

		this->StorageViewTV->SelectedNode = selNode;
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
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wska¿nika");
			return;
		}

		// Create new Container
		Item^ item = gcnew Item(
			this->newItemNameTB->Lines[0],
			System::String::Join(Environment::NewLine, this->newItemDescTB->Lines),
			0
		);

		// Create associated TreeNode
		TreeNode^ node = ComponentMutator::createTreeNode(item, false);

		// Put in master storage and add to graph
		targetStorage->place(item);
		selNode->Nodes->Add(node);
		this->StorageViewTV->Sort();

		// Add item to Items tab list
		ListViewItem^ listItem = gcnew ListViewItem;
		listItem->Text = item->getName();
		listItem->SubItems->Add(item->getQuantity().ToString());
		listItem->SubItems->Add(L"-");
		listItem->SubItems->Add(L"");
		listItem->SubItems->Add(item->getDescription());
		listItem->SubItems->Add(L"0");
		listItem->Tag = item;
		listItem->Name = item->getName();
		this->itemList->Items->Add(listItem);

		// Clean inputs
		this->newItemNameTB->Clear();
		this->newItemDescTB->Clear();

		this->StorageViewTV->SelectedNode = selNode;

		ProgramState::dbc->putDatabaseItemRecord(item->getName(), item->getDescription(), item->getQuantity());
	}

	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		this->StorageViewTV->Nodes[0]->Tag = ProgramState::masterStorage;
		this->StorageViewTV->SelectedNode = this->StorageViewTV->Nodes[0];
	}

	private: System::Void StorageViewTV_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
	{
		if (this->StorageViewTV->SelectedNode == nullptr
			|| this->StorageViewTV->SelectedNode == nullptr)
		{
			this->delItemBtn->Enabled = false;
			this->delStoreBtn->Enabled = false;
			this->emptyStoreBtn->Enabled = false;
			return;
		}

		bool isCompartment =
			this->StorageViewTV->SelectedNode->Tag->GetType()->Name == "Compartment";
		bool isItem = this->StorageViewTV->SelectedNode->Tag->GetType()->Name == "Item";

		this->delItemBtn->Enabled = isItem;
		this->delStoreBtn->Enabled = isCompartment;
		this->emptyStoreBtn->Enabled = isCompartment;

	}
	private: System::Void emptyStoreBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		clearErrors();

		// guard: no node selected
		if (this->StorageViewTV->SelectedNode == nullptr)
		{
			this->ErrorProvider->SetError(
				this->StorageViewTV,
				L"Wybierz, który pojemnik opró¿niæ"
			);
		}

		TreeNode^ selNode = this->StorageViewTV->SelectedNode;

		// guard: selected node points at Item
		if (selNode->Tag == ProgramState::masterStorage)
		{
			this->ErrorProvider->SetError(this->StorageViewTV,
				L"Aby opró¿niæ magazyn g³ówny wybierz Magazyn > Opró¿nij magazyn g³ówny");

			return;
		}

		IPlaceable^ target = dynamic_cast<IPlaceable^>(selNode->Tag);

		if (target == nullptr)
		{
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wska¿nika");
			return;
		}

		if (!ProgramState::confirmBox(
			L"Potwierdzenie",
			L"Czy na pewno chcesz opró¿niæ element " + selNode->Text + "? Tej czynnoœci nie mo¿na cofn¹æ",
			MessageBoxIcon::Warning
		)) return;

		this->itemList->BeginUpdate();

		auto listItems = target->getItems(); // All items in selected Compartment

		// for each item in selected Compartment
		for each (Item ^ item in listItems)
		{
			ComponentMutator::removeFromListView(this->itemList, item);
		}
		this->itemList->EndUpdate();

		target->zero();
		selNode->Nodes->Clear();

		this->StorageViewTV->SelectedNode = selNode;
	}
	
	private: System::Void emptyMainTSMI_Click(System::Object^ sender, System::EventArgs^ e)
	{
		clearErrors();
		if (!ProgramState::confirmBox(
			L"Potwierdzenie",
			L"Czy na pewno chcesz opró¿niæ magazyn g³ówny? Tej czynnoœci nie mo¿na cofn¹æ!",
			MessageBoxIcon::Warning
		)) return;

		while (ProgramState::masterStorage->getContents()->Count > 0)
		{
			ProgramState::masterStorage->remove(ProgramState::masterStorage->getContents()[0]);
		}

		this->StorageViewTV->Nodes[0]->Nodes->Clear();
		this->itemList->Items->Clear();
		this->StorageViewTV->SelectedNode = this->StorageViewTV->Nodes[0];
	}
	
	private: System::Void findItemBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (this->itemList->SelectedItems->Count < 1) return;

		Item^ item = dynamic_cast<Item^>(this->itemList->SelectedItems[0]->Tag);

		if (item == nullptr)
		{
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wska¿nika");
			return;
		}

		MessageBox::Show(
			String::Format("{0} znajduje siê w {1}", item->getName(), item->getPath()),
			L"Lokalizacja",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);
	}
	private: System::Void itemList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->itemList->SelectedItems->Count < 1)
		{
			this->findItemBtn->Enabled = false;
			this->setQuantityBtn->Enabled = false;
			this->setItemExpiryBtn->Enabled = false;
			this->delItemExpiryBtn->Enabled = false;
			this->setNotifQtyBtn->Enabled = false;
			return;
		}
		
		this->findItemBtn->Enabled = true;
		this->setQuantityBtn->Enabled = true;
		this->setItemExpiryBtn->Enabled = true;
		this->delItemExpiryBtn->Enabled = true;
		this->setNotifQtyBtn->Enabled = true;

		Item^ item = dynamic_cast<Item^>(this->itemList->SelectedItems[0]->Tag);

		if (item == nullptr)
		{
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wska¿nika");
			return;
		}

		this->itemQuantityNUD->Value = item->getQuantity();
		if (item->getDecayDate().Year < 9999) this->itemExpiryDTP->Value = item->getDecayDate();
	}
	private: System::Void setQuantityBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->itemList->SelectedItems->Count < 1) return;

		clearErrors();

		Item^ item = dynamic_cast<Item^>(this->itemList->SelectedItems[0]->Tag);

		if (item == nullptr)
		{
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wska¿nika");
			return;
		}

		item->setQuantity(static_cast<System::UInt16>(this->itemQuantityNUD->Value));
		this->itemList->SelectedItems[0]->SubItems[1]->Text = item->getQuantity().ToString();

		if (item->getQuantity() <= item->getAlertLevel())
		{
			this->itemList->SelectedItems[0]->ForeColor = System::Drawing::Color::Red;
		}
		else
		{
			this->itemList->SelectedItems[0]->ForeColor = System::Drawing::Color::Black;
		}
	}

	private: System::Void setItemExpiryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->itemList->SelectedItems->Count < 1) return;

		clearErrors();

		Item^ item = dynamic_cast<Item^>(this->itemList->SelectedItems[0]->Tag);

		if (item == nullptr)
		{
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wska¿nika");
			return;
		}

		item->setDecayDate(this->itemExpiryDTP->Value);
		this->itemList->SelectedItems[0]->SubItems[2]->Text = this->itemExpiryDTP->Value.ToShortDateString();

		if (item->getDecayDate() < System::DateTime::Now)
		{
			this->itemList->SelectedItems[0]->BackColor = System::Drawing::Color::DarkOrange;
		}
		else if (item->getDecayDate() < System::DateTime::Now.AddDays(2))
		{
			this->itemList->SelectedItems[0]->BackColor = System::Drawing::Color::Yellow;
		}
		else
		{
			this->itemList->SelectedItems[0]->BackColor = System::Drawing::Color::Transparent;
		}
	}
	private: System::Void delItemExpiryBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->itemList->SelectedItems->Count < 1) return;

		clearErrors();

		Item^ item = dynamic_cast<Item^>(this->itemList->SelectedItems[0]->Tag);

		if (item == nullptr)
		{
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wska¿nika");
			return;
		}

		item->setDecayDate(System::DateTime(9999, 1, 1, 0, 0, 0, 0));
		this->itemList->SelectedItems[0]->SubItems[2]->Text = L"-";
		this->itemList->SelectedItems[0]->BackColor = System::Drawing::Color::Transparent;
	}
	private: System::Void setNotifQtyBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->itemList->SelectedItems->Count < 1) return;

		clearErrors();

		Item^ item = dynamic_cast<Item^>(this->itemList->SelectedItems[0]->Tag);

		if (item == nullptr)
		{
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wska¿nika");
			return;
		}

		item->setAlertLevel(System::Decimal::ToUInt16(this->alertQtyNUD->Value));
		this->itemList->SelectedItems[0]->SubItems[5]->Text = this->alertQtyNUD->Value.ToString();

		if (item->getQuantity() <= item->getAlertLevel())
		{
			this->itemList->SelectedItems[0]->ForeColor = System::Drawing::Color::Red;
		}
		else
		{
			this->itemList->SelectedItems[0]->ForeColor = System::Drawing::Color::Black;
		}
	}

	private: System::Void odœwie¿ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ComponentMutator::regenerateList(this->itemList);
	}
	private: System::Void delStoreBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		clearErrors();

		if (!ProgramState::confirmBox(
			L"Potwierdzenie",
			L"Czy na pewno chcesz usun¹æ pojemnik i ca³¹ jego zawartoœæ? Tej czynnoœci nie mo¿na cofn¹æ",
			MessageBoxIcon::Warning
		)) return;

		if (this->StorageViewTV->SelectedNode == nullptr)
		{
			this->ErrorProvider->SetError(
				this->StorageViewTV,
				L"Wybierz, który pojemnik opró¿niæ"
			);
		}

		TreeNode^ selNode = this->StorageViewTV->SelectedNode;

		Compartment^ target = dynamic_cast<Compartment^>(selNode->Tag);

		if (target == nullptr)
		{
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wska¿nika");
			return;
		}

		this->itemList->BeginUpdate();

		auto listItems = target->getItems(); // All items in selected Compartment

		for each (Item ^ item in listItems)
		{
			ComponentMutator::removeFromListView(this->itemList, item);
		}
		this->itemList->EndUpdate();

		target->parent()->remove(target);
		selNode->Remove();

		lockStructTabBtns();
	}

	private: System::Void delItemBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		clearErrors();

		if (this->StorageViewTV->SelectedNode == nullptr)
		{
			this->ErrorProvider->SetError(
				this->StorageViewTV,
				L"Wybierz, który przedmiot usun¹æ"
			);
		}

		TreeNode^ selNode = this->StorageViewTV->SelectedNode;
		Item^ target = dynamic_cast<Item^>(selNode->Tag);

		if (target == nullptr)
		{
			ProgramState::handleError(L"Wybrany element nie zawiera prawid³owego wskaŸnika.");
			return;
		}

		target->parent()->remove(target);
		selNode->Remove();
		ComponentMutator::removeFromListView(this->itemList, target);
		
		lockStructTabBtns();
	}
	
	private: System::Void refreshStoreTSMI_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ComponentMutator::regenerateTree(this->StorageViewTV);
	}
	private: System::Void delAllItemsTSMI_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!ProgramState::confirmBox(
			L"Potwierdzenie",
			L"Czy na pewno chcesz usun¹æ pojemnik i ca³¹ jego zawartoœæ? Tej czynnoœci nie mo¿na cofn¹æ",
			MessageBoxIcon::Warning
		)) return;
		
		this->itemList->Items->Clear();

		this->StorageViewTV->BeginUpdate();
		ComponentMutator::removeAllItems(this->StorageViewTV->Nodes[0]);
		this->StorageViewTV->EndUpdate();


		System::Collections::Generic::List<IPlaceable^>^ flat = 
			ProgramState::flattenStorage(ProgramState::masterStorage);

		for each (IPlaceable ^ element in flat)
		{
			if (element->GetType()->Name == L"Item")
			{
				element->parent()->remove(element);
			}
		}
	}
	private: System::Void saveTSMI_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (DataReadWrite::FileIO::path == nullptr)
		{
			if (this->saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				DataReadWrite::FileIO::path = this->saveFileDialog1->FileName;
			}
			else return;
		}

		DataReadWrite::FileIO::write();
	}
	private: System::Void saveAsTSMI_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->saveFileDialog1->ShowDialog() != Windows::Forms::DialogResult::OK)
			return;
		
		DataReadWrite::FileIO::path = this->saveFileDialog1->FileName;
		DataReadWrite::FileIO::write();
	}
	private: System::Void openTSMI_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (this->openFileDialog->ShowDialog() != Windows::Forms::DialogResult::OK)
			return;

		DataReadWrite::FileIO::read(this->openFileDialog->FileName);
		ComponentMutator::regenerateTree(this->StorageViewTV);
		ComponentMutator::regenerateList(this->itemList);
	}
}; // end class
} // end namespace

// TODOS:
// Warnings tab [?]
// Editing functions
// Database
// Docs
// Warning manager
// Item list column widths
