#pragma once

namespace AUD_FX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AUD_FX_GUI
	/// </summary>
	public ref class AUD_FX_GUI : public System::Windows::Forms::Form
	{
	public:
		AUD_FX_GUI(void)
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
		~AUD_FX_GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newProjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openProjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importSongToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::Windows::Forms::Panel^  Audio_Control_Panel;
	private: System::Windows::Forms::Button^  Next_Song;

	private: System::Windows::Forms::Button^  Fast_Forward_Song;
	private: System::Windows::Forms::Button^  Stop_Song;



	private: System::Windows::Forms::Button^  Pause_Song;

	private: System::Windows::Forms::Button^  Rewind_Song;

	private: System::Windows::Forms::Button^  Restart_Song;
	private: System::Windows::Forms::Button^  Play_Song;
	private: System::Windows::Forms::TextBox^  File_Location_Output;
	private: System::Windows::Forms::Panel^  Effect_Panel;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RadioButton^  Phaser_Radio_Button;
	private: System::Windows::Forms::RadioButton^  Distortion_Radio_Button;
	private: System::Windows::Forms::RadioButton^  Vocal_Bleed_Radio_Button;
	private: System::Windows::Forms::RadioButton^  Karaoke_Radio_Button;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  effectsToolStripMenuItem;


	private: System::ComponentModel::IContainer^  components;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AUD_FX_GUI::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newProjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openProjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importSongToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->effectsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->Restart_Song = (gcnew System::Windows::Forms::Button());
			this->Audio_Control_Panel = (gcnew System::Windows::Forms::Panel());
			this->Play_Song = (gcnew System::Windows::Forms::Button());
			this->Next_Song = (gcnew System::Windows::Forms::Button());
			this->Fast_Forward_Song = (gcnew System::Windows::Forms::Button());
			this->Stop_Song = (gcnew System::Windows::Forms::Button());
			this->Pause_Song = (gcnew System::Windows::Forms::Button());
			this->Rewind_Song = (gcnew System::Windows::Forms::Button());
			this->File_Location_Output = (gcnew System::Windows::Forms::TextBox());
			this->Effect_Panel = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Phaser_Radio_Button = (gcnew System::Windows::Forms::RadioButton());
			this->Distortion_Radio_Button = (gcnew System::Windows::Forms::RadioButton());
			this->Vocal_Bleed_Radio_Button = (gcnew System::Windows::Forms::RadioButton());
			this->Karaoke_Radio_Button = (gcnew System::Windows::Forms::RadioButton());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->Audio_Control_Panel->SuspendLayout();
			this->Effect_Panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->viewToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1184, 37);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->newProjectToolStripMenuItem,
					this->openProjectToolStripMenuItem, this->importSongToolStripMenuItem, this->saveToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Vani", 12));
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(53, 33);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newProjectToolStripMenuItem
			// 
			this->newProjectToolStripMenuItem->Name = L"newProjectToolStripMenuItem";
			this->newProjectToolStripMenuItem->Size = System::Drawing::Size(180, 34);
			this->newProjectToolStripMenuItem->Text = L"New Project";
			this->newProjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::newProjectToolStripMenuItem_Click);
			// 
			// openProjectToolStripMenuItem
			// 
			this->openProjectToolStripMenuItem->Name = L"openProjectToolStripMenuItem";
			this->openProjectToolStripMenuItem->Size = System::Drawing::Size(180, 34);
			this->openProjectToolStripMenuItem->Text = L"Open Project";
			this->openProjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::openProjectToolStripMenuItem_Click);
			// 
			// importSongToolStripMenuItem
			// 
			this->importSongToolStripMenuItem->Name = L"importSongToolStripMenuItem";
			this->importSongToolStripMenuItem->Size = System::Drawing::Size(180, 34);
			this->importSongToolStripMenuItem->Text = L"Import Song";
			this->importSongToolStripMenuItem->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::importSongToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(180, 34);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::saveToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(180, 34);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::exitToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->effectsToolStripMenuItem });
			this->viewToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Vani", 12));
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(61, 33);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// effectsToolStripMenuItem
			// 
			this->effectsToolStripMenuItem->Name = L"effectsToolStripMenuItem";
			this->effectsToolStripMenuItem->Size = System::Drawing::Size(134, 34);
			this->effectsToolStripMenuItem->Text = L"Effects";
			this->effectsToolStripMenuItem->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::effectsToolStripMenuItem_Click);
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// Restart_Song
			// 
			this->Restart_Song->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Restart_Song.Image")));
			this->Restart_Song->Location = System::Drawing::Point(3, 3);
			this->Restart_Song->Name = L"Restart_Song";
			this->Restart_Song->Size = System::Drawing::Size(64, 64);
			this->Restart_Song->TabIndex = 1;
			this->Restart_Song->UseVisualStyleBackColor = true;
			this->Restart_Song->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::Restart_Song_Click);
			// 
			// Audio_Control_Panel
			// 
			this->Audio_Control_Panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->Audio_Control_Panel->Controls->Add(this->Play_Song);
			this->Audio_Control_Panel->Controls->Add(this->Next_Song);
			this->Audio_Control_Panel->Controls->Add(this->Fast_Forward_Song);
			this->Audio_Control_Panel->Controls->Add(this->Stop_Song);
			this->Audio_Control_Panel->Controls->Add(this->Pause_Song);
			this->Audio_Control_Panel->Controls->Add(this->Rewind_Song);
			this->Audio_Control_Panel->Controls->Add(this->Restart_Song);
			this->Audio_Control_Panel->Location = System::Drawing::Point(513, 52);
			this->Audio_Control_Panel->Name = L"Audio_Control_Panel";
			this->Audio_Control_Panel->Size = System::Drawing::Size(422, 75);
			this->Audio_Control_Panel->TabIndex = 2;
			// 
			// Play_Song
			// 
			this->Play_Song->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Play_Song.Image")));
			this->Play_Song->Location = System::Drawing::Point(143, 3);
			this->Play_Song->Name = L"Play_Song";
			this->Play_Song->Size = System::Drawing::Size(64, 64);
			this->Play_Song->TabIndex = 6;
			this->Play_Song->UseVisualStyleBackColor = true;
			this->Play_Song->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::Play_Song_Click);
			// 
			// Next_Song
			// 
			this->Next_Song->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Next_Song.Image")));
			this->Next_Song->Location = System::Drawing::Point(353, 3);
			this->Next_Song->Name = L"Next_Song";
			this->Next_Song->Size = System::Drawing::Size(64, 64);
			this->Next_Song->TabIndex = 6;
			this->Next_Song->UseVisualStyleBackColor = true;
			this->Next_Song->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::Next_Song_Click);
			// 
			// Fast_Forward_Song
			// 
			this->Fast_Forward_Song->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Fast_Forward_Song.Image")));
			this->Fast_Forward_Song->Location = System::Drawing::Point(283, 3);
			this->Fast_Forward_Song->Name = L"Fast_Forward_Song";
			this->Fast_Forward_Song->Size = System::Drawing::Size(64, 64);
			this->Fast_Forward_Song->TabIndex = 5;
			this->Fast_Forward_Song->UseVisualStyleBackColor = true;
			this->Fast_Forward_Song->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::Fast_Forward_Song_Click);
			// 
			// Stop_Song
			// 
			this->Stop_Song->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Stop_Song.Image")));
			this->Stop_Song->Location = System::Drawing::Point(213, 3);
			this->Stop_Song->Name = L"Stop_Song";
			this->Stop_Song->Size = System::Drawing::Size(64, 64);
			this->Stop_Song->TabIndex = 4;
			this->Stop_Song->UseVisualStyleBackColor = true;
			this->Stop_Song->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::Stop_Song_Click);
			// 
			// Pause_Song
			// 
			this->Pause_Song->Enabled = false;
			this->Pause_Song->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Pause_Song.Image")));
			this->Pause_Song->Location = System::Drawing::Point(143, 3);
			this->Pause_Song->Name = L"Pause_Song";
			this->Pause_Song->Size = System::Drawing::Size(64, 64);
			this->Pause_Song->TabIndex = 3;
			this->Pause_Song->UseVisualStyleBackColor = true;
			this->Pause_Song->Visible = false;
			this->Pause_Song->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::Pause_Song_Click);
			// 
			// Rewind_Song
			// 
			this->Rewind_Song->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Rewind_Song.Image")));
			this->Rewind_Song->Location = System::Drawing::Point(73, 3);
			this->Rewind_Song->Name = L"Rewind_Song";
			this->Rewind_Song->Size = System::Drawing::Size(64, 64);
			this->Rewind_Song->TabIndex = 2;
			this->Rewind_Song->UseVisualStyleBackColor = true;
			this->Rewind_Song->Click += gcnew System::EventHandler(this, &AUD_FX_GUI::Rewind_Song_Click);
			// 
			// File_Location_Output
			// 
			this->File_Location_Output->BackColor = System::Drawing::SystemColors::Control;
			this->File_Location_Output->Font = (gcnew System::Drawing::Font(L"Vani", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->File_Location_Output->Location = System::Drawing::Point(549, 0);
			this->File_Location_Output->Name = L"File_Location_Output";
			this->File_Location_Output->Size = System::Drawing::Size(635, 34);
			this->File_Location_Output->TabIndex = 3;
			// 
			// Effect_Panel
			// 
			this->Effect_Panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->Effect_Panel->Controls->Add(this->textBox1);
			this->Effect_Panel->Controls->Add(this->Phaser_Radio_Button);
			this->Effect_Panel->Controls->Add(this->Distortion_Radio_Button);
			this->Effect_Panel->Controls->Add(this->Vocal_Bleed_Radio_Button);
			this->Effect_Panel->Controls->Add(this->Karaoke_Radio_Button);
			this->Effect_Panel->Location = System::Drawing::Point(1027, 40);
			this->Effect_Panel->Name = L"Effect_Panel";
			this->Effect_Panel->Size = System::Drawing::Size(145, 287);
			this->Effect_Panel->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 8);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 31);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"Effects";
			// 
			// Phaser_Radio_Button
			// 
			this->Phaser_Radio_Button->AutoSize = true;
			this->Phaser_Radio_Button->Location = System::Drawing::Point(3, 109);
			this->Phaser_Radio_Button->Name = L"Phaser_Radio_Button";
			this->Phaser_Radio_Button->Size = System::Drawing::Size(58, 17);
			this->Phaser_Radio_Button->TabIndex = 3;
			this->Phaser_Radio_Button->TabStop = true;
			this->Phaser_Radio_Button->Text = L"Phaser";
			this->Phaser_Radio_Button->UseVisualStyleBackColor = true;
			this->Phaser_Radio_Button->CheckedChanged += gcnew System::EventHandler(this, &AUD_FX_GUI::Phaser_Radio_Button_CheckedChanged);
			// 
			// Distortion_Radio_Button
			// 
			this->Distortion_Radio_Button->AutoSize = true;
			this->Distortion_Radio_Button->Location = System::Drawing::Point(3, 86);
			this->Distortion_Radio_Button->Name = L"Distortion_Radio_Button";
			this->Distortion_Radio_Button->Size = System::Drawing::Size(69, 17);
			this->Distortion_Radio_Button->TabIndex = 2;
			this->Distortion_Radio_Button->TabStop = true;
			this->Distortion_Radio_Button->Text = L"Distortion";
			this->Distortion_Radio_Button->UseVisualStyleBackColor = true;
			this->Distortion_Radio_Button->CheckedChanged += gcnew System::EventHandler(this, &AUD_FX_GUI::Distortion_Radio_Button_CheckedChanged);
			// 
			// Vocal_Bleed_Radio_Button
			// 
			this->Vocal_Bleed_Radio_Button->AutoSize = true;
			this->Vocal_Bleed_Radio_Button->Location = System::Drawing::Point(3, 63);
			this->Vocal_Bleed_Radio_Button->Name = L"Vocal_Bleed_Radio_Button";
			this->Vocal_Bleed_Radio_Button->Size = System::Drawing::Size(82, 17);
			this->Vocal_Bleed_Radio_Button->TabIndex = 1;
			this->Vocal_Bleed_Radio_Button->TabStop = true;
			this->Vocal_Bleed_Radio_Button->Text = L"Vocal Bleed";
			this->Vocal_Bleed_Radio_Button->UseVisualStyleBackColor = true;
			this->Vocal_Bleed_Radio_Button->CheckedChanged += gcnew System::EventHandler(this, &AUD_FX_GUI::Vocal_Bleed_Radio_Button_CheckedChanged);
			// 
			// Karaoke_Radio_Button
			// 
			this->Karaoke_Radio_Button->AutoSize = true;
			this->Karaoke_Radio_Button->Location = System::Drawing::Point(3, 39);
			this->Karaoke_Radio_Button->Name = L"Karaoke_Radio_Button";
			this->Karaoke_Radio_Button->Size = System::Drawing::Size(65, 17);
			this->Karaoke_Radio_Button->TabIndex = 0;
			this->Karaoke_Radio_Button->TabStop = true;
			this->Karaoke_Radio_Button->Text = L"Karaoke";
			this->Karaoke_Radio_Button->UseVisualStyleBackColor = true;
			this->Karaoke_Radio_Button->CheckedChanged += gcnew System::EventHandler(this, &AUD_FX_GUI::Karaoke_Radio_Button_CheckedChanged);
			// 
			// AUD_FX_GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 682);
			this->Controls->Add(this->Effect_Panel);
			this->Controls->Add(this->File_Location_Output);
			this->Controls->Add(this->Audio_Control_Panel);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"AUD_FX_GUI";
			this->Text = L"AUD_FX_GUI";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->Audio_Control_Panel->ResumeLayout(false);
			this->Effect_Panel->ResumeLayout(false);
			this->Effect_Panel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//*******************************
//* Menu Strip Button functions *
//*******************************
private: System::Void newProjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 	
//Function: Creates a new project in AUD_FX
//Pre: None
//Post: Creates a new project space in a chosen folder
{
			//BLABLABLA
}

private: System::Void openProjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
//Function: Opens up an existing AUD_FX project file
//Pre: File Location is a valid AUD_FX file
//Post: File location has been returned
{

			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
			 System::Windows::Forms::DialogResult result = openFileDialog1->ShowDialog();
			 File_Location_Output->Text = openFileDialog1->FileName;
			 
}

private: System::Void importSongToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
//Function: Selects a song to import to AUD_FX
//Pre: File is a .wav file
//Post: File location has been returned
{

			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
			 System::Windows::Forms::DialogResult result = openFileDialog1->ShowDialog();
			 File_Location_Output->Text = openFileDialog1->FileName;

			 
}

private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
//Function: Saves an AUD_FX project file
//Pre: File has been created
//Post: Save Directory has been returned
{

			 SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
			 System::Windows::Forms::DialogResult result = saveFileDialog1->ShowDialog();
			 File_Location_Output->Text = saveFileDialog1->FileName;

			 //Proceed to save the file

}

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
//Function: Exits out of the AUD_FX Program
//Pre: None
//Post: Program will quit
{
	Close();
}

private: System::Void effectsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
//Function: Toggles the visibility of the effects panel to the user
//Pre: None
//Post: Effect panel will be toggled on or off
{
			 if (Effect_Panel->Visible == true)
			 {
				 Effect_Panel->Visible = false;
			 }
			 else
				 Effect_Panel->Visible = true;
}

//********************************
//* Song Control Panel Functions *
//********************************

private: System::Void Play_Song_Click(System::Object^  sender, System::EventArgs^  e) 
//Function: Begin playing music track
//Pre:Song has been loaded in
//Post: Music begins playing
{
			 Pause_Song->Enabled = true;
			 Pause_Song->Visible = true;
			 Play_Song->Enabled = false;
			 Play_Song->Visible = false;
}

private: System::Void Pause_Song_Click(System::Object^  sender, System::EventArgs^  e) 
//Function: Song is stopped at current marker
//Pre: Song is playing
//Post: Song will be paused at current marker
{
			 Play_Song->Enabled = true;
			 Play_Song->Visible = true;
			 Pause_Song->Enabled = true;
			 Pause_Song->Visible = true;
}

private: System::Void Stop_Song_Click(System::Object^  sender, System::EventArgs^  e) 
//Function: Stops the song entirely
//Pre: Song is playing
//Post: Song will be stopped and the marker reset
{

}

private: System::Void Fast_Forward_Song_Click(System::Object^  sender, System::EventArgs^  e) 
//Function: Begins Fast Forwarding the song
//Pre: Song has been loaded
//Post: Song will be accelerated
{

}

private: System::Void Rewind_Song_Click(System::Object^  sender, System::EventArgs^  e) 
//Function: Rewinds the song
//Pre: Song has been loaded
//Post: Song marker increments backwards
{

}

private: System::Void Restart_Song_Click(System::Object^  sender, System::EventArgs^  e) 
//Function: Restarts the Song from the beginning
//Pre: Song has been loaded
//Post: Sets the song marker to 0
{

}

//Note: We might never implement this function
private: System::Void Next_Song_Click(System::Object^  sender, System::EventArgs^  e) 
//Function: Loads in the next song to be played in the list
//Pre: Another song exists
//Post: Next .wav file in the same directory will be loaded in and begin to play
{

}

//*************************
//* Effects Radio Buttons *
//*************************

private: System::Void Karaoke_Radio_Button_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{

}

private: System::Void Vocal_Bleed_Radio_Button_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{

}

private: System::Void Distortion_Radio_Button_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{

}

private: System::Void Phaser_Radio_Button_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{

}


};
}
