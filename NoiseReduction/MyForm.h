#pragma once

namespace NoiseReduction {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ image, ^ startImage;
	private: System::Windows::Forms::Button^ button_reset;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button_points;
	private: System::Windows::Forms::Button^ button_circles;
	private: System::Windows::Forms::Button^ button_lines;
	private: System::Windows::Forms::Label^ label_lines;
	private: System::Windows::Forms::TrackBar^ trackBar_lines;
	private: System::Windows::Forms::Label^ label_points;
	private: System::Windows::Forms::Label^ label_circles;
	private: System::Windows::Forms::TrackBar^ trackBar_circles;
	private: System::Windows::Forms::TrackBar^ trackBar_kernelN;
	private: System::Windows::Forms::Button^ button_median;
	private: System::Windows::Forms::Label^ label_kernel;
	private: System::Windows::Forms::Button^ button_gaussian;
	private: System::Windows::Forms::Button^ button_sharpness;
	private: System::Windows::Forms::TrackBar^ trackBar_sigma;
	private: System::Windows::Forms::Label^ label_sigma;
	private: System::Windows::Forms::Label^ label_k;
	private: System::Windows::Forms::TrackBar^ trackBar_k;
	private: System::Windows::Forms::Button^ button_сontouring;
	private: System::Windows::Forms::Button^ button_contLaplas;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TrackBar^ trackBar_points;


	public:
		MyForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::Panel^ panel_image;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ button_openFile;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;

		   /// <summary>
		   /// Обязательная переменная конструктора.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Требуемый метод для поддержки конструктора — не изменяйте 
		   /// содержимое этого метода с помощью редактора кода.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->panel_image = (gcnew System::Windows::Forms::Panel());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->button_reset = (gcnew System::Windows::Forms::Button());
			   this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			   this->button_openFile = (gcnew System::Windows::Forms::Button());
			   this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			   this->trackBar_points = (gcnew System::Windows::Forms::TrackBar());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->button_contLaplas = (gcnew System::Windows::Forms::Button());
			   this->button_сontouring = (gcnew System::Windows::Forms::Button());
			   this->label_k = (gcnew System::Windows::Forms::Label());
			   this->trackBar_k = (gcnew System::Windows::Forms::TrackBar());
			   this->label_sigma = (gcnew System::Windows::Forms::Label());
			   this->trackBar_sigma = (gcnew System::Windows::Forms::TrackBar());
			   this->button_sharpness = (gcnew System::Windows::Forms::Button());
			   this->button_gaussian = (gcnew System::Windows::Forms::Button());
			   this->button_median = (gcnew System::Windows::Forms::Button());
			   this->label_kernel = (gcnew System::Windows::Forms::Label());
			   this->trackBar_kernelN = (gcnew System::Windows::Forms::TrackBar());
			   this->label_circles = (gcnew System::Windows::Forms::Label());
			   this->label_lines = (gcnew System::Windows::Forms::Label());
			   this->label_points = (gcnew System::Windows::Forms::Label());
			   this->button_circles = (gcnew System::Windows::Forms::Button());
			   this->button_lines = (gcnew System::Windows::Forms::Button());
			   this->button_points = (gcnew System::Windows::Forms::Button());
			   this->trackBar_circles = (gcnew System::Windows::Forms::TrackBar());
			   this->trackBar_lines = (gcnew System::Windows::Forms::TrackBar());
			   this->panel3 = (gcnew System::Windows::Forms::Panel());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->panel1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_points))->BeginInit();
			   this->panel2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_k))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_sigma))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_kernelN))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_circles))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_lines))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // panel_image
			   // 
			   this->panel_image->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->panel_image->Location = System::Drawing::Point(307, 31);
			   this->panel_image->Name = L"panel_image";
			   this->panel_image->Size = System::Drawing::Size(545, 653);
			   this->panel_image->TabIndex = 17;
			   this->panel_image->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_image_Paint);
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->button1);
			   this->panel1->Controls->Add(this->button_reset);
			   this->panel1->Controls->Add(this->panel3);
			   this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			   this->panel1->Location = System::Drawing::Point(302, 0);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(561, 702);
			   this->panel1->TabIndex = 26;
			   // 
			   // button_reset
			   // 
			   this->button_reset->Location = System::Drawing::Point(104, 2);
			   this->button_reset->Name = L"button_reset";
			   this->button_reset->Size = System::Drawing::Size(75, 23);
			   this->button_reset->TabIndex = 28;
			   this->button_reset->Text = L"Reset Image";
			   this->button_reset->UseVisualStyleBackColor = true;
			   this->button_reset->Click += gcnew System::EventHandler(this, &MyForm::button_reset_Click);
			   // 
			   // button_openFile
			   // 
			   this->button_openFile->Location = System::Drawing::Point(307, 2);
			   this->button_openFile->Name = L"button_openFile";
			   this->button_openFile->Size = System::Drawing::Size(75, 23);
			   this->button_openFile->TabIndex = 16;
			   this->button_openFile->Text = L"Open Image";
			   this->button_openFile->UseVisualStyleBackColor = true;
			   this->button_openFile->Click += gcnew System::EventHandler(this, &MyForm::button_openFile_Click);
			   // 
			   // trackBar_points
			   // 
			   this->trackBar_points->Location = System::Drawing::Point(3, 31);
			   this->trackBar_points->Maximum = 100;
			   this->trackBar_points->Minimum = 1;
			   this->trackBar_points->Name = L"trackBar_points";
			   this->trackBar_points->Size = System::Drawing::Size(293, 45);
			   this->trackBar_points->TabIndex = 18;
			   this->trackBar_points->Value = 50;
			   this->trackBar_points->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_points_Scroll);
			   // 
			   // panel2
			   // 
			   this->panel2->Controls->Add(this->button_contLaplas);
			   this->panel2->Controls->Add(this->button_сontouring);
			   this->panel2->Controls->Add(this->label_k);
			   this->panel2->Controls->Add(this->trackBar_k);
			   this->panel2->Controls->Add(this->label_sigma);
			   this->panel2->Controls->Add(this->trackBar_sigma);
			   this->panel2->Controls->Add(this->button_sharpness);
			   this->panel2->Controls->Add(this->button_gaussian);
			   this->panel2->Controls->Add(this->button_median);
			   this->panel2->Controls->Add(this->label_kernel);
			   this->panel2->Controls->Add(this->trackBar_kernelN);
			   this->panel2->Controls->Add(this->label_circles);
			   this->panel2->Controls->Add(this->label_lines);
			   this->panel2->Controls->Add(this->label_points);
			   this->panel2->Controls->Add(this->button_circles);
			   this->panel2->Controls->Add(this->button_lines);
			   this->panel2->Controls->Add(this->button_points);
			   this->panel2->Controls->Add(this->trackBar_circles);
			   this->panel2->Controls->Add(this->trackBar_lines);
			   this->panel2->Controls->Add(this->trackBar_points);
			   this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			   this->panel2->Location = System::Drawing::Point(0, 0);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(302, 702);
			   this->panel2->TabIndex = 27;
			   // 
			   // button_contLaplas
			   // 
			   this->button_contLaplas->Location = System::Drawing::Point(96, 633);
			   this->button_contLaplas->Name = L"button_contLaplas";
			   this->button_contLaplas->Size = System::Drawing::Size(75, 51);
			   this->button_contLaplas->TabIndex = 47;
			   this->button_contLaplas->Text = L"Contouring\r\n(laplasian)\r\n";
			   this->button_contLaplas->UseVisualStyleBackColor = true;
			   this->button_contLaplas->Click += gcnew System::EventHandler(this, &MyForm::button_contLaplas_Click);
			   // 
			   // button_сontouring
			   // 
			   this->button_сontouring->Location = System::Drawing::Point(12, 633);
			   this->button_сontouring->Name = L"button_сontouring";
			   this->button_сontouring->Size = System::Drawing::Size(75, 51);
			   this->button_сontouring->TabIndex = 46;
			   this->button_сontouring->Text = L"Contouring\r\n(gradient)\r\n";
			   this->button_сontouring->UseVisualStyleBackColor = true;
			   this->button_сontouring->Click += gcnew System::EventHandler(this, &MyForm::button_сontouring_Click);
			   // 
			   // label_k
			   // 
			   this->label_k->AutoSize = true;
			   this->label_k->Location = System::Drawing::Point(9, 559);
			   this->label_k->Name = L"label_k";
			   this->label_k->Size = System::Drawing::Size(13, 13);
			   this->label_k->TabIndex = 45;
			   this->label_k->Text = L"k";
			   // 
			   // trackBar_k
			   // 
			   this->trackBar_k->Location = System::Drawing::Point(3, 527);
			   this->trackBar_k->Minimum = 1;
			   this->trackBar_k->Name = L"trackBar_k";
			   this->trackBar_k->Size = System::Drawing::Size(293, 45);
			   this->trackBar_k->SmallChange = 2;
			   this->trackBar_k->TabIndex = 44;
			   this->trackBar_k->Value = 1;
			   this->trackBar_k->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_k_Scroll);
			   // 
			   // label_sigma
			   // 
			   this->label_sigma->AutoSize = true;
			   this->label_sigma->Location = System::Drawing::Point(9, 411);
			   this->label_sigma->Name = L"label_sigma";
			   this->label_sigma->Size = System::Drawing::Size(36, 13);
			   this->label_sigma->TabIndex = 43;
			   this->label_sigma->Text = L"Sigma";
			   // 
			   // trackBar_sigma
			   // 
			   this->trackBar_sigma->Location = System::Drawing::Point(3, 379);
			   this->trackBar_sigma->Maximum = 500;
			   this->trackBar_sigma->Minimum = 1;
			   this->trackBar_sigma->Name = L"trackBar_sigma";
			   this->trackBar_sigma->Size = System::Drawing::Size(293, 45);
			   this->trackBar_sigma->SmallChange = 2;
			   this->trackBar_sigma->TabIndex = 42;
			   this->trackBar_sigma->Value = 100;
			   this->trackBar_sigma->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_sigma_Scroll);
			   // 
			   // button_sharpness
			   // 
			   this->button_sharpness->Location = System::Drawing::Point(12, 578);
			   this->button_sharpness->Name = L"button_sharpness";
			   this->button_sharpness->Size = System::Drawing::Size(75, 23);
			   this->button_sharpness->TabIndex = 41;
			   this->button_sharpness->Text = L"Sharpness";
			   this->button_sharpness->UseVisualStyleBackColor = true;
			   this->button_sharpness->Click += gcnew System::EventHandler(this, &MyForm::button_sharpness_Click);
			   // 
			   // button_gaussian
			   // 
			   this->button_gaussian->Location = System::Drawing::Point(12, 463);
			   this->button_gaussian->Name = L"button_gaussian";
			   this->button_gaussian->Size = System::Drawing::Size(75, 23);
			   this->button_gaussian->TabIndex = 40;
			   this->button_gaussian->Text = L"Gaussian";
			   this->button_gaussian->UseVisualStyleBackColor = true;
			   this->button_gaussian->Click += gcnew System::EventHandler(this, &MyForm::button_gaussian_Click);
			   // 
			   // button_median
			   // 
			   this->button_median->Location = System::Drawing::Point(96, 463);
			   this->button_median->Name = L"button_median";
			   this->button_median->Size = System::Drawing::Size(75, 23);
			   this->button_median->TabIndex = 39;
			   this->button_median->Text = L"Median";
			   this->button_median->UseVisualStyleBackColor = true;
			   this->button_median->Click += gcnew System::EventHandler(this, &MyForm::button_median_Click);
			   // 
			   // label_kernel
			   // 
			   this->label_kernel->AutoSize = true;
			   this->label_kernel->Location = System::Drawing::Point(9, 360);
			   this->label_kernel->Name = L"label_kernel";
			   this->label_kernel->Size = System::Drawing::Size(15, 13);
			   this->label_kernel->TabIndex = 38;
			   this->label_kernel->Text = L"N";
			   // 
			   // trackBar_kernelN
			   // 
			   this->trackBar_kernelN->Location = System::Drawing::Point(3, 328);
			   this->trackBar_kernelN->Maximum = 9;
			   this->trackBar_kernelN->Minimum = 1;
			   this->trackBar_kernelN->Name = L"trackBar_kernelN";
			   this->trackBar_kernelN->Size = System::Drawing::Size(293, 45);
			   this->trackBar_kernelN->SmallChange = 2;
			   this->trackBar_kernelN->TabIndex = 37;
			   this->trackBar_kernelN->TickFrequency = 2;
			   this->trackBar_kernelN->Value = 1;
			   this->trackBar_kernelN->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_kernelN_Scroll);
			   // 
			   // label_circles
			   // 
			   this->label_circles->AutoSize = true;
			   this->label_circles->Location = System::Drawing::Point(93, 240);
			   this->label_circles->Name = L"label_circles";
			   this->label_circles->Size = System::Drawing::Size(35, 13);
			   this->label_circles->TabIndex = 36;
			   this->label_circles->Text = L"label1";
			   // 
			   // label_lines
			   // 
			   this->label_lines->AutoSize = true;
			   this->label_lines->Location = System::Drawing::Point(93, 160);
			   this->label_lines->Name = L"label_lines";
			   this->label_lines->Size = System::Drawing::Size(35, 13);
			   this->label_lines->TabIndex = 34;
			   this->label_lines->Text = L"label1";
			   // 
			   // label_points
			   // 
			   this->label_points->AutoSize = true;
			   this->label_points->Location = System::Drawing::Point(93, 79);
			   this->label_points->Name = L"label_points";
			   this->label_points->Size = System::Drawing::Size(35, 13);
			   this->label_points->TabIndex = 32;
			   this->label_points->Text = L"label1";
			   // 
			   // button_circles
			   // 
			   this->button_circles->Location = System::Drawing::Point(12, 230);
			   this->button_circles->Name = L"button_circles";
			   this->button_circles->Size = System::Drawing::Size(75, 23);
			   this->button_circles->TabIndex = 31;
			   this->button_circles->Text = L"Circles";
			   this->button_circles->UseVisualStyleBackColor = true;
			   this->button_circles->Click += gcnew System::EventHandler(this, &MyForm::button_circles_Click);
			   // 
			   // button_lines
			   // 
			   this->button_lines->Location = System::Drawing::Point(12, 150);
			   this->button_lines->Name = L"button_lines";
			   this->button_lines->Size = System::Drawing::Size(75, 23);
			   this->button_lines->TabIndex = 30;
			   this->button_lines->Text = L"Lines";
			   this->button_lines->UseVisualStyleBackColor = true;
			   this->button_lines->Click += gcnew System::EventHandler(this, &MyForm::button_lines_Click);
			   // 
			   // button_points
			   // 
			   this->button_points->Location = System::Drawing::Point(12, 69);
			   this->button_points->Name = L"button_points";
			   this->button_points->Size = System::Drawing::Size(75, 23);
			   this->button_points->TabIndex = 29;
			   this->button_points->Text = L"Points";
			   this->button_points->UseVisualStyleBackColor = true;
			   this->button_points->Click += gcnew System::EventHandler(this, &MyForm::button_points_Click);
			   // 
			   // trackBar_circles
			   // 
			   this->trackBar_circles->Location = System::Drawing::Point(3, 197);
			   this->trackBar_circles->Maximum = 100;
			   this->trackBar_circles->Minimum = 1;
			   this->trackBar_circles->Name = L"trackBar_circles";
			   this->trackBar_circles->Size = System::Drawing::Size(293, 45);
			   this->trackBar_circles->TabIndex = 35;
			   this->trackBar_circles->Value = 1;
			   this->trackBar_circles->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_circles_Scroll);
			   // 
			   // trackBar_lines
			   // 
			   this->trackBar_lines->Location = System::Drawing::Point(3, 117);
			   this->trackBar_lines->Maximum = 100;
			   this->trackBar_lines->Minimum = 1;
			   this->trackBar_lines->Name = L"trackBar_lines";
			   this->trackBar_lines->Size = System::Drawing::Size(293, 45);
			   this->trackBar_lines->TabIndex = 33;
			   this->trackBar_lines->Value = 1;
			   this->trackBar_lines->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_lines_Scroll);
			   // 
			   // panel3
			   // 
			   this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->panel3->Location = System::Drawing::Point(9, 31);
			   this->panel3->Name = L"panel3";
			   this->panel3->Size = System::Drawing::Size(545, 653);
			   this->panel3->TabIndex = 17;
			   this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_image_Paint);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(9, 2);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(75, 23);
			   this->button1->TabIndex = 16;
			   this->button1->Text = L"Open Image";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button_openFile_Click);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(863, 702);
			   this->Controls->Add(this->button_openFile);
			   this->Controls->Add(this->panel_image);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->panel2);
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->panel1->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_points))->EndInit();
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_k))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_sigma))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_kernelN))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_circles))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_lines))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void button_openFile_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void panel_image_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void button_reset_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_lines_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_circles_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_circles_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_lines_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_points_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_points_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_kernelN_Scroll(System::Object^ sender, System::EventArgs^ e);	
	private: System::Void button_median_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_gaussian_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_sharpness_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_sigma_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_k_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_сontouring_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_contLaplas_Click(System::Object^ sender, System::EventArgs^ e);
};
}
