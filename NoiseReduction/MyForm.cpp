#include "MyForm.h"
#include <vector>

System::Void NoiseReduction::MyForm::button_openFile_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Создаем и показываем диалог выбора файла
    OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
    openFileDialog->Filter = "Изображения|*.image;*.jpg;*.jpeg;*.png;*.gif;*.tiff|Все файлы|*.*";
    openFileDialog->Title = "Выберите изображение";

    // Если пользователь выбрал файл, загружаем его
    if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        try {
            // Загружаем изображение по выбранному пути
            image = gcnew Bitmap(openFileDialog->FileName);
            startImage = gcnew Bitmap(image);
            panel_image->Invalidate(); // Перерисовываем groupBox, чтобы отобразить изображение
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка загрузки изображения: " + ex->Message);
        }
    }
}

System::Void NoiseReduction::MyForm::panel_image_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
    // Если изображение загружено, рисуем его на форме
    if (image != nullptr) {
        panel_image->Width = image->Width;
        panel_image->Height = image->Height;
        e->Graphics->DrawImage(image, 0, 0, panel_image->ClientSize.Width, panel_image->ClientSize.Height);
    }
}

System::Void NoiseReduction::MyForm::button_reset_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (startImage) {
        image = gcnew Bitmap(startImage);
        panel_image->Invalidate();
    }
}

System::Void NoiseReduction::MyForm::button_lines_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!startImage) return;
    Graphics^ g = Graphics::FromImage(image);
    Random^ rand = gcnew Random();
    // Добавление линий шума
    for (int i = 0; i < trackBar_lines->Value; i++) {
        int x1 = rand->Next(image->Width);
        int y1 = rand->Next(image->Height);
        int x2 = rand->Next(image->Width);
        int y2 = rand->Next(image->Height);
        //Color color = Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256));
        Color color = Color::White;
        g->DrawLine(gcnew Pen(color), x1, y1, x2, y2);
    }
    panel_image->Invalidate();
    delete g;
}

System::Void NoiseReduction::MyForm::button_circles_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!startImage) return;
    Graphics^ g = Graphics::FromImage(image);
    Random^ rand = gcnew Random();
    // Добавление окружностей шума
    for (int i = 0; i < trackBar_circles->Value; i++)
    {
        int x = rand->Next(image->Width);
        int y = rand->Next(image->Height);
        int radius = rand->Next(10, 50);
        Color color = Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256));
        g->DrawEllipse(gcnew Pen(color), x - radius / 2, y - radius / 2, radius, radius);
    }
    panel_image->Invalidate();
    delete g;
}

System::Void NoiseReduction::MyForm::trackBar_circles_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label_circles->Text = "" + trackBar_circles->Value;
}

System::Void NoiseReduction::MyForm::trackBar_lines_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label_lines->Text = "" + trackBar_lines->Value;
}

System::Void NoiseReduction::MyForm::trackBar_points_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label_points->Text = ((double)trackBar_points->Value / 100).ToString();
}

System::Void NoiseReduction::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{ 
    label_circles->Text = "" + trackBar_circles->Value;
    label_lines->Text = "" + trackBar_lines->Value;
    label_points->Text = "" + ((double)trackBar_points->Value / 100).ToString();
    label_kernel->Text = "N: " + trackBar_kernelN->Value;
    label_sigma->Text = "Sigma: " + (double)trackBar_sigma->Value / 100;
    label_k->Text = "k: " + trackBar_k->Value;
}

System::Void NoiseReduction::MyForm::button_points_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!startImage) return;
    Random^ rand = gcnew Random();
    int width = image->Width;
    int height = image->Height;

    // Вычисляем количество пикселей, которые будут заменены
    int numPixels = static_cast<int>(width * height * trackBar_points->Value / 100);

    for (int i = 0; i < numPixels; i++) {
        int x = rand->Next(width);
        int y = rand->Next(height);

        // Случайным образом выбираем белый (соль) или черный (перец) пиксель
        Color noiseColor = (rand->NextDouble() > 0.5) ? Color::White : Color::Black;

        image->SetPixel(x, y, noiseColor);
    }
    panel_image->Invalidate();
}

System::Void NoiseReduction::MyForm::trackBar_kernelN_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label_kernel->Text = "N: " + trackBar_kernelN->Value;
}

System::Void NoiseReduction::MyForm::button_median_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!startImage) return;
    int width = image->Width;
    int height = image->Height;
    Bitmap^ result = gcnew Bitmap(width, height);

    int filterSize = trackBar_kernelN->Value;
    int halfFilterSize = filterSize / 2;
    for (int y = halfFilterSize; y < height - halfFilterSize; y++) {
        for (int x = halfFilterSize; x < width - halfFilterSize; x++) {
            List<int>^ rValues = gcnew List<int>();
            List<int>^ gValues = gcnew List<int>();
            List<int>^ bValues = gcnew List<int>();

            // Собираем значения пикселей в окрестности
            for (int ky = -halfFilterSize; ky <= halfFilterSize; ky++) {
                for (int kx = -halfFilterSize; kx <= halfFilterSize; kx++) {
                    Color pixelColor = image->GetPixel(x + kx, y + ky);
                    rValues->Add(pixelColor.R);
                    gValues->Add(pixelColor.G);
                    bValues->Add(pixelColor.B);
                }
            }

            // Сортируем значения и находим медиану
            rValues->Sort();
            gValues->Sort();
            bValues->Sort();

            int rMedian = rValues[rValues->Count / 2];
            int gMedian = gValues[gValues->Count / 2];
            int bMedian = bValues[bValues->Count / 2];

            result->SetPixel(x, y, Color::FromArgb(rMedian, gMedian, bMedian));
        }
    }
    image = gcnew Bitmap(result);
    panel_image->Invalidate();
}

System::Void NoiseReduction::MyForm::button_gaussian_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!startImage) return;
    
    int width = image->Width;
    int height = image->Height;
    Bitmap^ result = gcnew Bitmap(width, height);

    int filterSize = trackBar_kernelN->Value;
    double sigma = trackBar_sigma->Value / 100.0f;

    // Генерация ядра Гаусса
    std::vector<std::vector<double>> kernel(filterSize, std::vector<double>(filterSize, 0));
    double kernelSum = 0;
    int halfFilterSize = filterSize / 2;
    for (int y = -halfFilterSize; y <= halfFilterSize; y++) {
        for (int x = -halfFilterSize; x <= halfFilterSize; x++) {
            double value = exp(-(x * x + y * y) / (2 * sigma * sigma));
            kernel[y + halfFilterSize][x + halfFilterSize] = value;
            kernelSum += value;
        }
    }

    // Нормализуем ядро
    for (int y = 0; y < filterSize; y++) {
        for (int x = 0; x < filterSize; x++) {
            kernel[y][x] /= kernelSum;
        }
    }

    // Применяем фильтр
    for (int y = halfFilterSize; y < height - halfFilterSize; y++) {
        for (int x = halfFilterSize; x < width - halfFilterSize; x++) {
            double rValue = 0;
            double gValue = 0;
            double bValue = 0;

            for (int ky = -halfFilterSize; ky <= halfFilterSize; ky++) {
                for (int kx = -halfFilterSize; kx <= halfFilterSize; kx++) {
                    Color pixelColor = image->GetPixel(x + kx, y + ky);
                    rValue += pixelColor.R * kernel[ky + halfFilterSize][kx + halfFilterSize];
                    gValue += pixelColor.G * kernel[ky + halfFilterSize][kx + halfFilterSize];
                    bValue += pixelColor.B * kernel[ky + halfFilterSize][kx + halfFilterSize];
                }
            }

            int r = std::min(std::max(rValue, 0.0), 255.0);
            int g = std::min(std::max(gValue, 0.0), 255.0);
            int b = std::min(std::max(bValue, 0.0), 255.0);

            result->SetPixel(x, y, Color::FromArgb(r, g, b));
        }
    }

    image = gcnew Bitmap(result);
    delete result;

    panel_image->Invalidate();
}

System::Void NoiseReduction::MyForm::button_sharpness_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!startImage) return;

    int width = image->Width;
    int height = image->Height;
    Bitmap^ result = gcnew Bitmap(width, height);

    int filterSize = trackBar_kernelN->Value;
    int halfFilterSize = filterSize / 2;
    int k = trackBar_k->Value;
    
    // Генерация ядра фильтра резкости
    double aroundK = -k / (double)((filterSize * filterSize) - 1);
    std::vector<std::vector<double>> kernel(filterSize, std::vector<double>(filterSize, aroundK));
    kernel[filterSize / 2][filterSize / 2] = k + 1;

    // Применяем фильтр
    for (int y = halfFilterSize; y < height - halfFilterSize; y++) {
        for (int x = halfFilterSize; x < width - halfFilterSize; x++) {
            double rValue = 0;
            double gValue = 0;
            double bValue = 0;

            for (int ky = -halfFilterSize; ky <= halfFilterSize; ky++) {
                for (int kx = -halfFilterSize; kx <= halfFilterSize; kx++) {
                    Color pixelColor = image->GetPixel(x + kx, y + ky);
                    rValue += pixelColor.R * kernel[ky + halfFilterSize][kx + halfFilterSize];
                    gValue += pixelColor.G * kernel[ky + halfFilterSize][kx + halfFilterSize];
                    bValue += pixelColor.B * kernel[ky + halfFilterSize][kx + halfFilterSize];
                }
            }

            int r = std::min(std::max(rValue, 0.0), 255.0);
            int g = std::min(std::max(gValue, 0.0), 255.0);
            int b = std::min(std::max(bValue, 0.0), 255.0);

            result->SetPixel(x, y, Color::FromArgb(r, g, b));
        }
    }

    image = gcnew Bitmap(result);
    delete result;

    panel_image->Invalidate();
}

System::Void NoiseReduction::MyForm::trackBar_sigma_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label_sigma->Text = "Sigma: " + (double)trackBar_sigma->Value / 100;
}

System::Void NoiseReduction::MyForm::trackBar_k_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label_k->Text = "k: " + trackBar_k->Value;
}

System::Void NoiseReduction::MyForm::button_сontouring_Click(System::Object^ sender, System::EventArgs^ e)
{
    int width = image->Width;
    int height = image->Height;
    Bitmap^ result = gcnew Bitmap(width, height);

    // Ядра Собеля для градиентов по X и Y
    int Gx[3][3] = {
        { -1,  0,  1 },
        { -2,  0,  2 },
        { -1,  0,  1 }
    };

    int Gy[3][3] = {
        { -1, -2, -1 },
        {  0,  0,  0 },
        {  1,  2,  1 }
    };

    // Применяем оператор Собеля
    for (int x = 1; x < width - 1; x++) {
        for (int y = 1; y < height - 1; y++) {
            int gradX = 0, gradY = 0;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    Color pixelColor = image->GetPixel(x + i, y + j);
                    int Y = (int)(0.299 * pixelColor.R + 0.587 * pixelColor.G + 0.114 * pixelColor.B);

                    gradX += Y * Gx[i + 1][j + 1];
                    gradY += Y * Gy[i + 1][j + 1];
                }
            }

            // Вычисляем величину градиента
            int gradient = (int)sqrt(gradX * gradX + gradY * gradY);
            gradient = Math::Min(Math::Max(gradient, 0), 255); // Ограничиваем в пределах [0, 255]

            result->SetPixel(x, y, Color::FromArgb(gradient, gradient, gradient));
        }
    }

    image = gcnew Bitmap(result);
    delete result;

    panel_image->Invalidate();
}

System::Void NoiseReduction::MyForm::button_contLaplas_Click(System::Object^ sender, System::EventArgs^ e)
{
    int width = image->Width;
    int height = image->Height;
    Bitmap^ result = gcnew Bitmap(width, height);

    // Ядро Лапласа
    int kernel[3][3] = {
        {  0, -1,  0 },
        { -1,  4, -1 },
        {  0, -1,  0 }
    };

    // Применяем фильтр Лапласа
    for (int x = 1; x < width - 1; x++) {
        for (int y = 1; y < height - 1; y++) {
            int sum = 0;

            // Применяем фильтр к соседним пикселям
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    Color pixelColor = image->GetPixel(x + i, y + j);
                    int Y = (int)(0.299 * pixelColor.R + 0.587 * pixelColor.G + 0.114 * pixelColor.B);
                    sum += Y * kernel[i + 1][j + 1];
                }
            }

            // Ограничиваем значение в пределах [0, 255]
            int edge = Math::Min(Math::Max(abs(sum), 0), 255);
            result->SetPixel(x, y, Color::FromArgb(edge, edge, edge));
        }
    }

    image = gcnew Bitmap(result);
    delete result;

    panel_image->Invalidate();
}

