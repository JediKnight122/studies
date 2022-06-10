#pragma once
#include <string>
#include "GameManager.h"

namespace Detective {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	string actionBoxElemente[15] = {};
	string actionTextLog;
	GameManager* gameManager = new GameManager();
	int currentRoomNumber = 0;
	int iNumberOfTurns = 0;

	/// <summary>
	/// Zusammenfassung für MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	

	public:
		MyForm(void)
		{
			InitializeComponent();

			
			gameManager->Init();
			AddNewLineToActionLog("Willkommen zu Indicium, dem bald klassischen Detektivspiel! \nEin Schrei zerreisst die Nacht auf Schloss Dunkelfels.\nDer Gärtner wurde tot auf der Veranda gefunden. Doch wer ist der Mörder?\n\nSie müssen diese Frage klären, Detective, in dem Sie die verschiedenen Verdächtigen befragen.\nErheben Sie, wenn Sie sich sicher sind, Anklage, in dem die auf das Icon des Mörders klicken.\nDoch wählen Sie mit Bedacht. Sie haben nur einen Versuch. Wählen Sie die falsche Person, so wird der Mörder dies nutzen, um sich in dem Trubel aus dem Staub zu machen.\nBetreten Sie einen Raum, um zu Beginnen.");

			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}
	
	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel2;
	protected:
	private: System::Windows::Forms::PictureBox^ playerImage;
	private: System::Windows::Forms::Button^ button_hall;
	private: System::Windows::Forms::Button^ button_salon;
	private: System::Windows::Forms::Button^ button_dining_room;
	private: System::Windows::Forms::Button^ button_buero;
	private: System::Windows::Forms::Button^ button_bibliothek;
	private: System::Windows::Forms::Button^ button_billiard;
	private: System::Windows::Forms::Button^ button_veranda;
	private: System::Windows::Forms::Button^ button_living_room;
	private: System::Windows::Forms::Button^ button_kitchen;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button_next_round;


	private: System::Windows::Forms::Button^ Sbutton_frau_weiss;

	private: System::Windows::Forms::Button^ Sbutton_frau_wiesental;
	private: System::Windows::Forms::Button^ Sbutton_baronin;
	private: System::Windows::Forms::Button^ Sbutton_Hausmeister;

	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::BindingSource^ bindingSource1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ Sbutton_oberst;
	private: System::Windows::Forms::Button^ Sbutton_anton;
	private: System::Windows::Forms::Button^ Sbutton_reverend;




	protected: 






	public: System::Windows::Forms::Label^ ActionFeed;












	
	public:
	private:

	private:

	public:





	public:
	private:
		void Indict(int susNr) {
			DeactivateMovementButtons();
			button_next_round->Enabled = false;

			if (gameManager->CheckIfIsMurder(susNr)) {
				ClearActionLog();
				AddNewLineToActionLog("Hervorragende Arbeit! Du hast den Mordfall aufgeklaert!\nWeiter so!\n\n...Beende Verbindung.");
			}
			else {
				AddNewLineToActionLog("Oh nein!\n Da hast du falsche Schlüsse gezogen und beinahe einen Unschuldigen hinter Gitter gebracht.\nAusserdem ist der Moerder entkommen.\nDas gibts doch nicht...\n\n...Schalte System ab...");
			}
		}

		void NextRound() {
			iNumberOfTurns++;
			AddNewLineToActionLog(gameManager->MoveAI(currentRoomNumber)); //Move AI Characters and print the protocol.
			ActivateMovementButtons();
			AddNewLineToActionLog("Du bist am Zug.");
		}

		void DeactivateMovementButtons() {
			button_hall->Enabled = false;
			button_buero->Enabled = false;
			button_kitchen->Enabled = false;
			button_veranda->Enabled = false;
			button_salon->Enabled = false;
			button_bibliothek->Enabled = false;
			button_billiard->Enabled = false;
			button_dining_room->Enabled = false;
			button_living_room->Enabled = false;

			//Naechste Runde noetig
			button_next_round->Enabled = true;

		}
		void ActivateMovementButtons() {
			button_hall->Enabled = true;
			button_buero->Enabled = true;
			button_kitchen->Enabled = true;
			button_veranda->Enabled = true;
			button_salon->Enabled = true;
			button_bibliothek->Enabled = true;
			button_billiard->Enabled = true;
			button_dining_room->Enabled = true;
			button_living_room->Enabled = true;

			//Naechste Runde verboten
			button_next_round->Enabled = false;
		}



	public:
		
		void EnterRoom(int roomNr) {
			currentRoomNumber = roomNr;
			DeactivateMovementButtons();
			ClearActionLog();
			AddNewLineToActionLog("\n**************************************\nDu betrittst "+gameManager->GetRoomArtikel(roomNr) +" "+gameManager->GetRoomName(roomNr) + ".\n\n");
			
			
			int iPeopleInRoom = gameManager->GetNumPeopleInRoom(roomNr);

			//Anzeige Teil 1: Welche Suspects befinden sich im Raum?
			if (iPeopleInRoom==0) AddNewLineToActionLog("Es befinden sich keine Verdächtigen "+ gameManager->GetRoomPraeposition(roomNr) +" "+ gameManager->GetRoomName(roomNr)+".\n");
			else {
				AddNewLineToActionLog("Du findest folgende Personen " + gameManager->GetRoomPraeposition(roomNr) + " " + gameManager->GetRoomName(roomNr) + ":\n");
				for (int i = 0; i < iPeopleInRoom; i++)
				{
					AddNewLineToActionLog(gameManager->GetPersonName(roomNr, i) + "\n");
				}
				AddNewLineToActionLog("\n");

				//Anzeige Teil 2: Deko Konvervsationen....
				// 
				//Anzeige Teil 3: Welche Personen können die Suspects decken?
				for (int i = 0; i < iPeopleInRoom; i++)
				{
					AddNewLineToActionLog(gameManager->GetPersonName(roomNr, i)+ ": Es war ganz sicher nicht "+gameManager->GetAlibiName(roomNr, i) + "!\n");
				}
				AddNewLineToActionLog("\n");

			}
		}





		void ClearActionLog() {
			for (int i = 0; i < 15; i++) {
				actionBoxElemente[i] = "";
			}
		}

		void AddNewLineToActionLog(string line) {
			actionTextLog = "";
			for (int i = 0; i < 14; i++) {
				actionBoxElemente[i] = actionBoxElemente[i + 1];
			}
			
		actionBoxElemente[14] = line;
		

		for (int i = 0; i < 15; i++) {
			
			actionTextLog += actionBoxElemente[i];
		}

		//ActionFeed->Text=(gcnew String(actionBoxElemente[8].c_str()));
		ActionFeed->Text = (gcnew String(actionTextLog.c_str()));
		}
private: System::ComponentModel::IContainer^ components;
public:


	protected:

	protected:
	
	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ActionFeed = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->playerImage = (gcnew System::Windows::Forms::PictureBox());
			this->button_hall = (gcnew System::Windows::Forms::Button());
			this->button_salon = (gcnew System::Windows::Forms::Button());
			this->button_dining_room = (gcnew System::Windows::Forms::Button());
			this->button_buero = (gcnew System::Windows::Forms::Button());
			this->button_bibliothek = (gcnew System::Windows::Forms::Button());
			this->button_billiard = (gcnew System::Windows::Forms::Button());
			this->button_veranda = (gcnew System::Windows::Forms::Button());
			this->button_living_room = (gcnew System::Windows::Forms::Button());
			this->button_kitchen = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Sbutton_frau_weiss = (gcnew System::Windows::Forms::Button());
			this->Sbutton_frau_wiesental = (gcnew System::Windows::Forms::Button());
			this->Sbutton_baronin = (gcnew System::Windows::Forms::Button());
			this->Sbutton_Hausmeister = (gcnew System::Windows::Forms::Button());
			this->button_next_round = (gcnew System::Windows::Forms::Button());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->Sbutton_oberst = (gcnew System::Windows::Forms::Button());
			this->Sbutton_reverend = (gcnew System::Windows::Forms::Button());
			this->Sbutton_anton = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playerImage))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// ActionFeed
			// 
			this->ActionFeed->BackColor = System::Drawing::Color::Transparent;
			this->ActionFeed->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ActionFeed->Font = (gcnew System::Drawing::Font(L"Martina", 17.25F));
			this->ActionFeed->ForeColor = System::Drawing::Color::White;
			this->ActionFeed->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ActionFeed.Image")));
			this->ActionFeed->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->ActionFeed->Location = System::Drawing::Point(-2, 0);
			this->ActionFeed->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ActionFeed->MaximumSize = System::Drawing::Size(512, 512);
			this->ActionFeed->Name = L"ActionFeed";
			this->ActionFeed->Size = System::Drawing::Size(512, 460);
			this->ActionFeed->TabIndex = 4;
			this->ActionFeed->Text = L"Person Name verließ den Salon.\r\nPerson Name verließ das Bad.\r\nPerson Name betritt"
				L" das Büro.\r\nPerson Name Betritt die Halle.\r\n";
			this->ActionFeed->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// panel2
			// 
			this->panel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->playerImage);
			this->panel2->Controls->Add(this->button_hall);
			this->panel2->Controls->Add(this->button_salon);
			this->panel2->Controls->Add(this->button_dining_room);
			this->panel2->Controls->Add(this->button_buero);
			this->panel2->Controls->Add(this->button_bibliothek);
			this->panel2->Controls->Add(this->button_billiard);
			this->panel2->Controls->Add(this->button_veranda);
			this->panel2->Controls->Add(this->button_living_room);
			this->panel2->Controls->Add(this->button_kitchen);
			this->panel2->Location = System::Drawing::Point(-200, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(8);
			this->panel2->MaximumSize = System::Drawing::Size(2560, 1440);
			this->panel2->MinimumSize = System::Drawing::Size(1280, 720);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1959, 1000);
			this->panel2->TabIndex = 1;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel2_Paint);
			// 
			// playerImage
			// 
			this->playerImage->BackColor = System::Drawing::Color::White;
			this->playerImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"playerImage.BackgroundImage")));
			this->playerImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->playerImage->Location = System::Drawing::Point(372, 119);
			this->playerImage->Name = L"playerImage";
			this->playerImage->Size = System::Drawing::Size(91, 81);
			this->playerImage->TabIndex = 12;
			this->playerImage->TabStop = false;
			this->playerImage->Visible = false;
			// 
			// button_hall
			// 
			this->button_hall->AutoSize = true;
			this->button_hall->BackColor = System::Drawing::Color::Transparent;
			this->button_hall->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_hall->Location = System::Drawing::Point(597, 697);
			this->button_hall->Margin = System::Windows::Forms::Padding(2);
			this->button_hall->Name = L"button_hall";
			this->button_hall->Size = System::Drawing::Size(224, 248);
			this->button_hall->TabIndex = 5;
			this->button_hall->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button_hall->UseVisualStyleBackColor = false;
			this->button_hall->Click += gcnew System::EventHandler(this, &MyForm::button_hall_Click_1);
			// 
			// button_salon
			// 
			this->button_salon->AutoSize = true;
			this->button_salon->BackColor = System::Drawing::Color::Transparent;
			this->button_salon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_salon->Location = System::Drawing::Point(269, 743);
			this->button_salon->Margin = System::Windows::Forms::Padding(2);
			this->button_salon->Name = L"button_salon";
			this->button_salon->Size = System::Drawing::Size(253, 216);
			this->button_salon->TabIndex = 6;
			this->button_salon->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button_salon->UseVisualStyleBackColor = false;
			this->button_salon->Click += gcnew System::EventHandler(this, &MyForm::button_salon_Click);
			// 
			// button_dining_room
			// 
			this->button_dining_room->AutoSize = true;
			this->button_dining_room->BackColor = System::Drawing::Color::Transparent;
			this->button_dining_room->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_dining_room->Location = System::Drawing::Point(269, 366);
			this->button_dining_room->Margin = System::Windows::Forms::Padding(2);
			this->button_dining_room->Name = L"button_dining_room";
			this->button_dining_room->Size = System::Drawing::Size(294, 263);
			this->button_dining_room->TabIndex = 7;
			this->button_dining_room->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button_dining_room->UseVisualStyleBackColor = false;
			this->button_dining_room->Click += gcnew System::EventHandler(this, &MyForm::button_dining_room_Click);
			// 
			// button_buero
			// 
			this->button_buero->AutoSize = true;
			this->button_buero->BackColor = System::Drawing::Color::Transparent;
			this->button_buero->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_buero->Location = System::Drawing::Point(898, 791);
			this->button_buero->Margin = System::Windows::Forms::Padding(2);
			this->button_buero->Name = L"button_buero";
			this->button_buero->Size = System::Drawing::Size(256, 154);
			this->button_buero->TabIndex = 15;
			this->button_buero->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button_buero->UseVisualStyleBackColor = false;
			this->button_buero->Click += gcnew System::EventHandler(this, &MyForm::button_buero_Click);
			// 
			// button_bibliothek
			// 
			this->button_bibliothek->AutoSize = true;
			this->button_bibliothek->BackColor = System::Drawing::Color::Transparent;
			this->button_bibliothek->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_bibliothek->Location = System::Drawing::Point(898, 548);
			this->button_bibliothek->Margin = System::Windows::Forms::Padding(2);
			this->button_bibliothek->Name = L"button_bibliothek";
			this->button_bibliothek->Size = System::Drawing::Size(256, 182);
			this->button_bibliothek->TabIndex = 6;
			this->button_bibliothek->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button_bibliothek->UseVisualStyleBackColor = false;
			this->button_bibliothek->Click += gcnew System::EventHandler(this, &MyForm::button_bibliothek_Click);
			// 
			// button_billiard
			// 
			this->button_billiard->AutoSize = true;
			this->button_billiard->BackColor = System::Drawing::Color::Transparent;
			this->button_billiard->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_billiard->Location = System::Drawing::Point(924, 327);
			this->button_billiard->Margin = System::Windows::Forms::Padding(2);
			this->button_billiard->Name = L"button_billiard";
			this->button_billiard->Size = System::Drawing::Size(230, 182);
			this->button_billiard->TabIndex = 8;
			this->button_billiard->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button_billiard->UseVisualStyleBackColor = false;
			this->button_billiard->Click += gcnew System::EventHandler(this, &MyForm::button_billiard_Click);
			// 
			// button_veranda
			// 
			this->button_veranda->AutoSize = true;
			this->button_veranda->BackColor = System::Drawing::Color::Transparent;
			this->button_veranda->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_veranda->Location = System::Drawing::Point(924, 75);
			this->button_veranda->Margin = System::Windows::Forms::Padding(2);
			this->button_veranda->Name = L"button_veranda";
			this->button_veranda->Size = System::Drawing::Size(230, 182);
			this->button_veranda->TabIndex = 9;
			this->button_veranda->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button_veranda->UseVisualStyleBackColor = false;
			this->button_veranda->Click += gcnew System::EventHandler(this, &MyForm::button_veranda_Click);
			// 
			// button_living_room
			// 
			this->button_living_room->AutoSize = true;
			this->button_living_room->BackColor = System::Drawing::Color::Transparent;
			this->button_living_room->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_living_room->Location = System::Drawing::Point(545, 50);
			this->button_living_room->Margin = System::Windows::Forms::Padding(2);
			this->button_living_room->Name = L"button_living_room";
			this->button_living_room->Size = System::Drawing::Size(312, 284);
			this->button_living_room->TabIndex = 10;
			this->button_living_room->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button_living_room->UseVisualStyleBackColor = false;
			this->button_living_room->Click += gcnew System::EventHandler(this, &MyForm::button_living_room_Click);
			// 
			// button_kitchen
			// 
			this->button_kitchen->AutoSize = true;
			this->button_kitchen->BackColor = System::Drawing::Color::Transparent;
			this->button_kitchen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_kitchen->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_kitchen->Location = System::Drawing::Point(269, 50);
			this->button_kitchen->Margin = System::Windows::Forms::Padding(2);
			this->button_kitchen->Name = L"button_kitchen";
			this->button_kitchen->Size = System::Drawing::Size(211, 241);
			this->button_kitchen->TabIndex = 11;
			this->button_kitchen->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button_kitchen->UseVisualStyleBackColor = false;
			this->button_kitchen->Click += gcnew System::EventHandler(this, &MyForm::button_kitchen_Click);
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(450, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(8);
			this->panel1->MaximumSize = System::Drawing::Size(2560, 1440);
			this->panel1->MinimumSize = System::Drawing::Size(1280, 720);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1920, 1080);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// Sbutton_frau_weiss
			// 
			this->Sbutton_frau_weiss->BackColor = System::Drawing::Color::Transparent;
			this->Sbutton_frau_weiss->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sbutton_frau_weiss->Location = System::Drawing::Point(0, 3);
			this->Sbutton_frau_weiss->Name = L"Sbutton_frau_weiss";
			this->Sbutton_frau_weiss->Size = System::Drawing::Size(207, 211);
			this->Sbutton_frau_weiss->TabIndex = 18;
			this->Sbutton_frau_weiss->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->Sbutton_frau_weiss->UseVisualStyleBackColor = false;
			this->Sbutton_frau_weiss->Click += gcnew System::EventHandler(this, &MyForm::Sbutton_frau_weiss_Click);
			// 
			// Sbutton_frau_wiesental
			// 
			this->Sbutton_frau_wiesental->BackColor = System::Drawing::Color::Transparent;
			this->Sbutton_frau_wiesental->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sbutton_frau_wiesental->Location = System::Drawing::Point(0, 220);
			this->Sbutton_frau_wiesental->Name = L"Sbutton_frau_wiesental";
			this->Sbutton_frau_wiesental->Size = System::Drawing::Size(207, 205);
			this->Sbutton_frau_wiesental->TabIndex = 20;
			this->Sbutton_frau_wiesental->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->Sbutton_frau_wiesental->UseVisualStyleBackColor = false;
			this->Sbutton_frau_wiesental->Click += gcnew System::EventHandler(this, &MyForm::Sbutton_frau_wiesental_Click);
			// 
			// Sbutton_baronin
			// 
			this->Sbutton_baronin->BackColor = System::Drawing::Color::Transparent;
			this->Sbutton_baronin->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sbutton_baronin->Location = System::Drawing::Point(213, 3);
			this->Sbutton_baronin->Name = L"Sbutton_baronin";
			this->Sbutton_baronin->Size = System::Drawing::Size(201, 211);
			this->Sbutton_baronin->TabIndex = 19;
			this->Sbutton_baronin->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->Sbutton_baronin->UseVisualStyleBackColor = false;
			this->Sbutton_baronin->Click += gcnew System::EventHandler(this, &MyForm::Sbutton_baronin_Click);
			// 
			// Sbutton_Hausmeister
			// 
			this->Sbutton_Hausmeister->BackColor = System::Drawing::Color::Transparent;
			this->Sbutton_Hausmeister->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sbutton_Hausmeister->Location = System::Drawing::Point(213, 220);
			this->Sbutton_Hausmeister->Name = L"Sbutton_Hausmeister";
			this->Sbutton_Hausmeister->Size = System::Drawing::Size(204, 205);
			this->Sbutton_Hausmeister->TabIndex = 21;
			this->Sbutton_Hausmeister->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->Sbutton_Hausmeister->UseVisualStyleBackColor = false;
			this->Sbutton_Hausmeister->Click += gcnew System::EventHandler(this, &MyForm::Sbutton_Hausmeister_Click);
			// 
			// button_next_round
			// 
			this->button_next_round->BackColor = System::Drawing::Color::Transparent;
			this->button_next_round->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_next_round.BackgroundImage")));
			this->button_next_round->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_next_round->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_next_round->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.25F));
			this->button_next_round->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button_next_round->Location = System::Drawing::Point(27, 505);
			this->button_next_round->Name = L"button_next_round";
			this->button_next_round->Size = System::Drawing::Size(441, 124);
			this->button_next_round->TabIndex = 5;
			this->button_next_round->Text = L"Nächste Runde";
			this->button_next_round->UseVisualStyleBackColor = false;
			this->button_next_round->Click += gcnew System::EventHandler(this, &MyForm::button_next_round_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->BackColor = System::Drawing::SystemColors::Highlight;
			this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.25F));
			this->checkedListBox1->ForeColor = System::Drawing::SystemColors::Info;
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Frau Weiss", L"Baronin von Porz", L"Frau Wiesental",
					L"Hausmeister", L"Oberst von Gatow", L"Reverend Gruen", L"Sir Anton"
			});
			this->checkedListBox1->Location = System::Drawing::Point(27, 756);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(421, 249);
			this->checkedListBox1->TabIndex = 6;
			this->checkedListBox1->ThreeDCheckBoxes = true;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::checkedListBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.25F));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(29, 714);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 39);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Hat Alibi\?";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_2);
			// 
			// panel3
			// 
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel3->Controls->Add(this->Sbutton_Hausmeister);
			this->panel3->Controls->Add(this->Sbutton_baronin);
			this->panel3->Controls->Add(this->Sbutton_frau_wiesental);
			this->panel3->Controls->Add(this->Sbutton_oberst);
			this->panel3->Controls->Add(this->Sbutton_anton);
			this->panel3->Controls->Add(this->Sbutton_reverend);
			this->panel3->Controls->Add(this->Sbutton_frau_weiss);
			this->panel3->Location = System::Drawing::Point(1188, 120);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(417, 853);
			this->panel3->TabIndex = 16;
			// 
			// Sbutton_oberst
			// 
			this->Sbutton_oberst->BackColor = System::Drawing::Color::Transparent;
			this->Sbutton_oberst->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sbutton_oberst->Location = System::Drawing::Point(3, 428);
			this->Sbutton_oberst->Name = L"Sbutton_oberst";
			this->Sbutton_oberst->Size = System::Drawing::Size(207, 205);
			this->Sbutton_oberst->TabIndex = 22;
			this->Sbutton_oberst->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->Sbutton_oberst->UseVisualStyleBackColor = false;
			this->Sbutton_oberst->Click += gcnew System::EventHandler(this, &MyForm::Sbutton_oberst_Click);
			// 
			// Sbutton_reverend
			// 
			this->Sbutton_reverend->BackColor = System::Drawing::Color::Transparent;
			this->Sbutton_reverend->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sbutton_reverend->Location = System::Drawing::Point(210, 428);
			this->Sbutton_reverend->Name = L"Sbutton_reverend";
			this->Sbutton_reverend->Size = System::Drawing::Size(207, 205);
			this->Sbutton_reverend->TabIndex = 23;
			this->Sbutton_reverend->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->Sbutton_reverend->UseVisualStyleBackColor = false;
			this->Sbutton_reverend->Click += gcnew System::EventHandler(this, &MyForm::Sbutton_reverend_Click);
			// 
			// Sbutton_anton
			// 
			this->Sbutton_anton->BackColor = System::Drawing::Color::Transparent;
			this->Sbutton_anton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Sbutton_anton->Location = System::Drawing::Point(0, 634);
			this->Sbutton_anton->Name = L"Sbutton_anton";
			this->Sbutton_anton->Size = System::Drawing::Size(207, 205);
			this->Sbutton_anton->TabIndex = 24;
			this->Sbutton_anton->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->Sbutton_anton->UseVisualStyleBackColor = false;
			this->Sbutton_anton->Click += gcnew System::EventHandler(this, &MyForm::Sbutton_anton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->button_next_round);
			this->Controls->Add(this->ActionFeed);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->Text = L"Detective Game";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playerImage))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}

	   
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_hall_Click_1(System::Object^ sender, System::EventArgs^ e) {
	EnterRoom(1);
}
private: System::Void button_buero_Click(System::Object^ sender, System::EventArgs^ e) {
	EnterRoom(2);
}
private: System::Void button_bibliothek_Click(System::Object^ sender, System::EventArgs^ e) {
	EnterRoom(3);
}
private: System::Void button_salon_Click(System::Object^ sender, System::EventArgs^ e) {
	EnterRoom(0);
}
private: System::Void button_living_room_Click(System::Object^ sender, System::EventArgs^ e) {
	EnterRoom(6);
}
private: System::Void button_veranda_Click(System::Object^ sender, System::EventArgs^ e) {
	EnterRoom(5);
}
private: System::Void button_billiard_Click(System::Object^ sender, System::EventArgs^ e) {
	EnterRoom(4);
}
private: System::Void button_kitchen_Click(System::Object^ sender, System::EventArgs^ e) {
	EnterRoom(7);
}
private: System::Void button_dining_room_Click(System::Object^ sender, System::EventArgs^ e) {
	//AddNewLineToActionLog("Betritt Esszimmer\n");
	EnterRoom(8);
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_next_round_Click(System::Object^ sender, System::EventArgs^ e) {
	NextRound();
}
private: System::Void fontDialog1_Apply(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void suspectList_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void Sbutton_anton_Click(System::Object^ sender, System::EventArgs^ e) {
	Indict(5);
}
private: System::Void Sbutton_reverend_Click(System::Object^ sender, System::EventArgs^ e) {
	Indict(6);
}
private: System::Void Sbutton_oberst_Click(System::Object^ sender, System::EventArgs^ e) {
	Indict(1);
}
private: System::Void Sbutton_Hausmeister_Click(System::Object^ sender, System::EventArgs^ e) {
	Indict(3);
}
private: System::Void Sbutton_frau_wiesental_Click(System::Object^ sender, System::EventArgs^ e) {
	Indict(2);
}
private: System::Void Sbutton_baronin_Click(System::Object^ sender, System::EventArgs^ e) {
	Indict(4);
}
private: System::Void Sbutton_frau_weiss_Click(System::Object^ sender, System::EventArgs^ e) {
	Indict(0);
}
};
}
