#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// The ImageEditor class manages PPM (Portable Pixmap) images.
class ImageEditor {
private:
    int width, height, max_color; // Dimensions and maximum color value of the image.
    // 3D vector to store the image data. Outer vector is for rows, inner vector is for columns,
    // and the innermost vector stores RGB values.
    vector<vector<vector<int>>> pixels;

public:
    // Function prototypes
    void printMainMenu();
    void printOpenImageMenu();
    void printSaveImageMenu();
    void printScriptsMenu();
    void printGrayscaleMenu();

    void runProgram();
    void runOpenImageMenu();
    void runSaveImageMenu();
    void runScriptsMenu();
    void runGrayscaleMenu();

    void openImage(const string& filename);
    void saveImage(const string& filename);
    void convertToGrayscale(float c_r, float c_g, float c_b);
};

// Opens a PPM image file and reads its content into the pixels vector.
void ImageEditor::openImage(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string type;
    file >> type >> width >> height >> max_color;
    pixels.resize(height, vector<vector<int>>(width, vector<int>(3)));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file >> pixels[i][j][0] >> pixels[i][j][1] >> pixels[i][j][2];
        }
    }
    cout << "Image loaded successfully." << endl;
    file.close();
}

// Saves the current image data to a PPM file.
void ImageEditor::saveImage(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error writing to file: " << filename << endl;
        return;
    }

    file << "P3\n" << width << " " << height << "\n" << max_color << "\n";
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file << pixels[i][j][0] << " " << pixels[i][j][1] << " " << pixels[i][j][2] << " ";
        }
        file << "\n";
    }
    cout << "Image saved successfully." << endl;
    file.close();
}

// Converts the current image to grayscale using provided coefficients for RGB channels.
void ImageEditor::convertToGrayscale(float c_r, float c_g, float c_b) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int gray = static_cast<int>(c_r * pixels[i][j][0] + c_g * pixels[i][j][1] + c_b * pixels[i][j][2]);
            gray = min(max(gray, 0), 255);
            pixels[i][j][0] = pixels[i][j][1] = pixels[i][j][2] = gray;
        }
    }
    cout << "Image converted to grayscale." << endl;
}

// Main program flow: Presents the main menu and handles user input.
void ImageEditor::runProgram() {
    int menuChoice;
    do {
        printMainMenu();
        cin >> menuChoice;
        cin.ignore(); // Clear newline character after the input

        switch (menuChoice) {
        case 0:
            cout << "Exiting Program." << endl;
            break;
        case 1:
            runOpenImageMenu();
            break;
        case 2:
            runSaveImageMenu();
            break;
        case 3:
            runScriptsMenu();
            break;
        default:
            cout << "Invalid entry. Please try again." << endl;
            break;
        }
    } while (menuChoice != 0);
}

// Each "run" method below manages a submenu, showing the menu, taking user input, and executing the corresponding action.

void ImageEditor::printMainMenu() {
    cout << "\nMAIN MENU\n"
        << "0 - Exit\n"
        << "1 - Open An Image\n"
        << "2 - Save Image Data\n"
        << "3 - Scripts\n";
}

void ImageEditor::printOpenImageMenu() {
    cout << "\nOPEN AN IMAGE MENU\n"
        << "0 - Back\n"
        << "1 - Enter The Name Of The Image File\n";
}

void ImageEditor::printSaveImageMenu() {
    cout << "\nSAVE IMAGE DATA MENU\n"
        << "0 - Back\n"
        << "1 - Enter A File Name\n";
}

void ImageEditor::printScriptsMenu() {
    cout << "\nSCRIPTS MENU\n"
        << "0 - Back\n"
        << "1 - Convert To Grayscale\n";
}

void ImageEditor::printGrayscaleMenu() {
    cout << "\nCONVERT TO GRAYSCALE MENU\n"
        << "0 - Back\n"
        << "1 - Enter Coefficients For RED GREEN And BLUE Channels\n";
}

// Definitions for runOpenImageMenu, runSaveImageMenu, runScriptsMenu, and runGrayscaleMenu would follow a similar pattern
// to runProgram, but are omitted for brevity. Each would present their submenu, handle user selections, and call the
// appropriate member functions like openImage, saveImage, or convertToGrayscale.

int main() {
    ImageEditor editor;
    editor.runProgram();
    return 0;
}
