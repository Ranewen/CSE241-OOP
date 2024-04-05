#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//max resolutions 500X500  
const int _MAX_X_ = 500;
const int _MAX_Y_ = 500;

// This class holds the red, green, and blue components of a pixel.
class Pixels{
    
public:
    Pixels()
        : r(0), g(0), b(0)
    {/*intentionally left blank*/}
    
    // Returns the values of the red, green, and blue components.
    int getR() const {return r;}
    int getG() const {return g;}
    int getB() const {return b;}

    // Returns references to the red, green, and blue components.
    int& getR_ref() {return r;}
    int& getG_ref() {return g;}
    int& getB_ref() {return b;}
    
    // Sets the values of the red, green, and blue components.
    void setR(const int _r) {r = _r;}
    void setG(const int _g) {g = _g;}
    void setB(const int _b) {b = _b;}
    
private:
    int r;
    int g;
    int b;

};

// This class represents an image in the PPM file format.
class PpmImage{
public:
	/*Constructors*/
	// Default constructor.
	PpmImage() 
	{/*intentionally left blank*/}
	
	// Constructor that sets the filename.
	PpmImage(const string _fileName_)
		: fileName(_fileName_)
		{/*intentionally left blank*/}
		
	// Constructor that sets the dimensions of the image.
	PpmImage(const int _dX, const int _dY) 
		: dX(_dX), dY(_dY)
		{/*intentionally left blank*/}
	
	// Member functions.
	int pixelInfo(const int x, const int y, const int code) const; // Returns RGB values according to the parameters ('r', 'g', 'b').
	bool savePpmToFile() const; // Saves the current object to a file.
	void readPpmFromFile(const string file);	// Reads a PPM file and creates (maybe) an object.
	void printDimensions() const {cout<<dX<<"x"<<dY<<endl;} // Prints the dimensions to the screen, e.g. "4x4".
	void printPixel(const int _x, const int _y); // Prints the specified pixel to the screen.
	void modifyPixel(const int _x, const int _y, const int r, const int g, const int b);
	void initializePixelVector();
	void resizeVector();
	
	// Overloaded operators.
	friend const PpmImage operator+(const PpmImage& left, const PpmImage& right);
	friend const PpmImage operator-(const PpmImage& left, const PpmImage& right);
	friend ostream& operator<<(ostream& out, const PpmImage& obj);
	int& operator()(int row, int col, int channel);

	/*Getters*/
	// Returns a reference to the pixel vector.
	vector<vector<Pixels> >& getVector() {return pixelVector;}
	
	// Returns a const reference to the pixel vector.
	vector<vector<Pixels> > const& getVector()const {return pixelVector;}
	
	// Returns the PPM file version.
	string getVersion()const {return version;}
	
	// Returns the maximum color value.
	int getMax()const {return max;}
	
	// Returns the width of the image.
	int getdX()const {return dX;}
	
	// Returns the height of the image.
	int getdY()const {return dY;}

	/*Setters*/
	// Sets the PPM file version.
	void setVersion(const string& s) {version = s;}
	
	// Sets the maximum color value.
	void setMax(const int x) {max = x;}
	
	// Sets the width of the image.
	void setdX(const int x) {dX = x;}
	
	// Sets the height of the image.
	void setdY(const int y) {dY = y;}

private:
	vector <vector <Pixels> >  pixelVector; // Stores the pixel data.
	string fileName; // Stores the filename.
	int dX; // Stores the width of the image.
	int dY;	// Stores the height of the image.
	int pixelCount; // Stores how many pixels there are.
	string version = "P3"; // Stores the PPM file version.
	int max = 255; // Stores the maximum color value.
};
// HW2 FUNCTIONS
int read_ppm(const string source_ppm_file_name, PpmImage& destination_object);
int swap_channels(PpmImage& image_object_to_be_modified, int swap_choice);	//re-implement with () operator
PpmImage single_color(const PpmImage& source, int color_choice);	//re-implement with () operator
int write_ppm(const string destination_ppm_file_name,  const PpmImage& source_object);

// HW3 FUNCTIONS
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3);
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3);
int test_print(const string filename_image1);


// This function tests the addition operation of two PpmImage objects and saves the result to a file
// Inputs:
// - filename_image1: name of the first input PPM image file
// - filename_image2: name of the second input PPM image file
// - filename_image3: name of the output PPM image file
// Returns:
// - 0 if the addition operation is successful and the result is saved to the file
// - 1 if an error occurs during the operation
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3)
{
	int control = 1;
	PpmImage image1, image2, image3(0,0);
	//for avoidng segmentation fault in the case the sizes are not equal
	vector<vector<Pixels> >& s = image3.getVector();
	s.resize(1);

	control = read_ppm(filename_image1,image1);
	control = read_ppm(filename_image2,image2);
	if((image1.getdX() == image2.getdX()) && (image1.getdY() == image2.getdY()) )
		image3 = image1 + image2;

	control = write_ppm(filename_image3,image3);
	if(control==1)
		return 1;
	return 0;
}

// This function tests the subtraction operation of two PpmImage objects and saves the result to a file
// Inputs:
// - filename_image1: name of the first input PPM image file
// - filename_image2: name of the second input PPM image file
// - filename_image3: name of the output PPM image file
// Returns:
// - 0 if the subtraction operation is successful and the result is saved to the file
// - 1 if an error occurs during the operation
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3)
{
	int control = 1;
	PpmImage image1, image2, image3(0,0);
	//for avoidng segmentation fault in the case the sizes are not equal
	vector<vector<Pixels> >& s = image3.getVector();
	s.resize(1);

	control = read_ppm(filename_image1,image1);
	control = read_ppm(filename_image2,image2);
	if(image1.getdX() == image2.getdX() && image1.getdY() == image2.getdY() )
		image3 = image1 - image2;
	
	control = write_ppm(filename_image3,image3);
	if(control==1)
		return 1;
	return 0;
}

// This function tests the printing of a PpmImage object to the console
// Inputs:
// - filename_image1: name of the input PPM image file
// Returns:
// - 0 if the printing is successful
// - 1 if an error occurs during the printing
int test_print(const string filename_image1)
{
	int control = 1;
	PpmImage obj;
	control = read_ppm(filename_image1, obj);
	cout<<obj;

	if(control==1)
		return 1;
	return 0;
}

// This overloaded operator is used to access and modify individual pixel values of the PpmImage object.
// It takes in three parameters, the row, column, and channel of the pixel that will be accessed/modified.
// The channel parameter determines which RGB channel of the pixel will be accessed/modified.
// The function returns a reference to the corresponding RGB channel of the specified pixel.
// If the specified channel parameter is not valid, it returns a reference to the red channel of the top-left pixel.
// This is because if an invalid channel is given, we assume that there is no choice other than 1, 2, or 3.
// Therefore, it returns a value just to avoid a compiler warning.
int& PpmImage::operator()(int row, int col, int channel)
{	
	if(channel == 1)
		return pixelVector[row][col].getR_ref(); 
	else if(channel == 2)
		return pixelVector[row][col].getG_ref(); 
	else if (channel == 3)
		return pixelVector[row][col].getB_ref(); 
	return pixelVector[0][0].getR_ref(); //we assume that there is no choice other than 1, 2,3
	//for that reason just returns something
}

// Overloaded << operator for printing PpmImage object to ostream.
// Prints the PpmImage object in the ppm file format.
// First prints the ppm file version, then the dimensions, and the maximum color value.
// After that, it prints the rgb values of each pixel in the image.
// Each row of pixels is printed on a separate line, and the values of each pixel is separated by spaces.
// The rgb values of each pixel are printed in the order of R, G, and B.
ostream& operator<<(ostream& out, const PpmImage& obj)
{
	out<<obj.version<<endl; // print ppm file version
	out<<obj.dX<<" "<<obj.dY<<endl; // print dimensions
	out<<obj.max<<endl; // print maximum color value
	// print pixel values of each row, separated by spaces
	for(int i=0; i<obj.pixelVector.size(); i++)
	{
		for(int k=0; k<obj.pixelVector[i].size(); k++)
		{
			out<<obj.pixelVector[i][k].getR()<<" "; // print red value
			out<<obj.pixelVector[i][k].getG()<<" "; // print green value
			out<<obj.pixelVector[i][k].getB()<<" "; // print blue value
			out<<"   "; // separate values by spaces
		}
		out<<endl; // move to the next line for the next row of pixels
	}
	return out;
}

// This function overloads the + operator to perform pixel-wise addition between two PpmImage objects.
// The resulting image is returned as a new PpmImage object.
// The function first checks if the two images have the same height and width. If so, it creates a new PpmImage object with the same properties as the left image.
// Then, it loops through the pixels of both images and adds the corresponding RGB values together.
// If the sum is greater than 255, it is clamped to 255 to prevent overflow.
// Finally, the RGB values of the new pixel are set and the resulting PpmImage object is returned.
const PpmImage operator+(const PpmImage& left, const PpmImage& right)
{
	int r,g,b;
	PpmImage newObj;
	newObj.setdX(left.getdX()); 
	newObj.setdY(left.getdY());
	newObj.setVersion(left.getVersion());
	newObj.setMax(left.getMax()); 
	if(right.pixelVector.size() == left.pixelVector.size())
	{
		vector <vector <Pixels> >& vec = newObj.getVector();; 	 
		vec.resize(left.pixelVector.size());
		for(int i=0; i<right.pixelVector.size(); i++)
		{
			vec[i].resize(left.pixelVector[i].size());
			for(int k=0; k<right.pixelVector[i].size(); k++)
			{
				// addition operation happens here
				r = right.pixelVector[i][k].getR() + left.pixelVector[i][k].getR();
				g = right.pixelVector[i][k].getG() + left.pixelVector[i][k].getG();
				b = right.pixelVector[i][k].getB() + left.pixelVector[i][k].getB();
				
				// we are assuming that both have same max value which is 255*/
				if(r>255) r=255;
				if(g>255) g=255;
				if(b>255) b=255;
				// setting
				vec[i][k].setR(r);
				vec[i][k].setG(g);
				vec[i][k].setB(b);
			}
		}

	}
	return newObj;
}

// This function overloads the '-' operator to perform pixel-wise subtraction of two PpmImage objects.
// It creates a new PpmImage object and sets its properties (version, dX, dY, max) to the same values as the left object.
// It then checks whether the size of the pixel vector of the right object is the same as that of the left object.
// If they are the same, it resizes the pixel vector of the new object to the same size and performs the subtraction operation
// by iterating over the pixels in the left and right objects and subtracting their color channels.
// The resulting color values are then checked to ensure they are not below the minimum value of 0 and assigned to the new object's pixels.
// Finally, the new object is returned.
const PpmImage operator-(const PpmImage& left, const PpmImage& right)
{
	int r,g,b;
	PpmImage newObj;
	newObj.setdX(left.getdX()); 
	newObj.setdY(left.getdY());
	newObj.setVersion(left.getVersion());
	newObj.setMax(left.getMax()); 
	if(right.pixelVector.size() == left.pixelVector.size())
	{
		vector <vector <Pixels> >& vec = newObj.getVector();; 	 
		vec.resize(left.pixelVector.size());

		for(int i=0; i<left.pixelVector.size(); i++)
		{
			vec[i].resize(left.pixelVector[i].size());
			for(int k=0; k<left.pixelVector[i].size(); k++)
			{
				//substraction happens here
				r = left.pixelVector[i][k].getR() - right.pixelVector[i][k].getR();
				g = left.pixelVector[i][k].getG() - right.pixelVector[i][k].getG();
				b = left.pixelVector[i][k].getB() - right.pixelVector[i][k].getB();
				/*we are assuming that both have same min value which is 0*/
				if(r<0) r=0;
				if(g<0) g=0;
				if(b<0) b=0;
				vec[i][k].setR(r);
				vec[i][k].setG(g);
				vec[i][k].setB(b);
			}
		}
	}
	return newObj;
}

// This function modifies the RGB values of a pixel at the given coordinates (_x, _y)
// with the provided values (r, g, b).
void PpmImage::modifyPixel(const int _x, const int _y, const int r, const int g, const int b)
{
	pixelVector[_x][_y].setR(r);
	pixelVector[_x][_y].setG(g);
	pixelVector[_x][_y].setB(b);
}

// Prints the specified pixel to screen
void PpmImage::printPixel(const int _x, const int _y) 
{
	// Print the RGB values of the pixel at (_x, _y)
	cout<<pixelVector[_x][_y].getR()<<" "
	<<pixelVector[_x][_y].getG()<<" "<<pixelVector[_x][_y].getB()<<endl;
}

// The function reads a PPM file and stores the RGB values for each pixel in a vector. 
// It checks that the file has the correct format (P3) and that the dimensions and RGB values are within the valid range (0-255). 
// If the file format or the RGB values are incorrect, the function sets the fileFormatIsTrue variable to false and prints an error message. 
// Otherwise, it resizes the vector according to the dimensions of the file and sets the RGB values for each pixel. Finally, it closes the file.
void PpmImage::readPpmFromFile(const string file)
{
	// Open the file
	ifstream fin;
	fin.open(file);

	// Initialize variables
	string temp;
	int d1, d2, maxColor;
	int _r, _g, _b;
	bool fileFormatIsTrue = true;

	// Check if the file is open
	if (fin.is_open())
	{
		// Read the file version
		fin >> temp;
		if (temp == "P3")
			version = temp;
		else
			fileFormatIsTrue = false;

		// Read the dimensions
		fin >> d1 >> d2;
		if (d1 <= _MAX_X_ && d2 <= _MAX_Y_ && fileFormatIsTrue == true)
		{
			dX = d1;
			dY = d2;
		}
		else
			fileFormatIsTrue = false;

		// Read the max RGB values
		fin >> maxColor;
		if (maxColor <= 255 && fileFormatIsTrue == true)
			max = maxColor;
		else
			fileFormatIsTrue = false;

		// Resize the vector according to the new dimensions
		if (fileFormatIsTrue)
			resizeVector();
		else
			cout << "File format is not true! Please check it." << endl;

		// Read the RGB values for each pixel
		if (fileFormatIsTrue)
		{
			for (int i = 0; i < dX; i++)
			{
				for (int k = 0; k < dY; k++)
				{
					fin >> _r >> _g >> _b;
					if (fileFormatIsTrue == true)
					{
						// Check if RGB values are within the valid range (0-255)
						if (_r < 0) _r = 0;
						if (_r > 255) _r = 255;
						if (_g < 0) _g = 0;
						if (_g > 255) _g = 255;
						if (_b < 0) _b = 0;
						if (_b > 255) _b = 255;

						// Set the RGB values for the pixel
						pixelVector[i][k].setR(_r);
						pixelVector[i][k].setG(_g);
						pixelVector[i][k].setB(_b);
					}
					else
					{
						fileFormatIsTrue = false;
						cout << "The RGB values are improper! Please check them." << endl;
						break;
					}
				}

				if (!fileFormatIsTrue)
					break;
			}
		}

		// Close the file
		fin.close();
	}
	else
	{
		cerr << "Error while opening the file!" << endl;
		fileFormatIsTrue = false;
	}
}

// This function returns the color value (red, green, or blue) of a pixel at a specific coordinate
// Parameters:
//   - x: the x-coordinate of the pixel
//   - y: the y-coordinate of the pixel
//   - code: an integer representing the color channel to return: 1 for red, 2 for green, 3 for blue
// Returns:
//   - The color value (int) of the specified color channel at the specified pixel coordinate.
//     If an unexpected color code is given, it returns -1 and prints an error message to the console.
int PpmImage::pixelInfo(const int x, const int y, const int code) const
{
    int r_value = -1;
    if(code == 1) // If the code is 1, return the red color value
        r_value = pixelVector[x][y].getR();
    else if(code == 2) // If the code is 2, return the green color value
        r_value =  pixelVector[x][y].getG();
    else if(code == 3)// If the code is 3, return the blue color value
        r_value =  pixelVector[x][y].getB();
    else cerr<<"unexpected color code!!"<<endl; // If the code is unexpected, print an error message and set r_value to -1.
    return r_value; // Return the color value.
}

// This function initializes each pixel in the vector to a white color by setting the R, G, and B values to 255. 
// It first resizes the vector to match the dimensions of the class, 
// and then uses nested loops to set the RGB values for each element in the vector.
void PpmImage::initializePixelVector()
{
	resizeVector(); // Resize vector with class's dimensions

	// Loop through each element of the vector and set R, G, and B values to 255
	for(int i=0; i<pixelVector.size(); i++)
	{
		for(int k=0; k < pixelVector[i].size(); k++)
		{
			pixelVector[i][k].setR(255 );
			pixelVector[i][k].setG(255 );
			pixelVector[i][k].setB(255 );
		}
	}		
}

// This function resizes the pixelVector member variable of the PpmImage class to the dimensions specified by the dX and dY member variables. 
// It first resizes the vector to the correct width by calling pixelVector.resize(dX). 
// Then it loops through each row of the vector and resizes it to the correct height by calling pixelVector[i].resize(dY). 
// This ensures that the pixelVector is the correct size to store all of the pixel information for the image.
void PpmImage::resizeVector()
{
	// resize the vector to the specified dimensions
	pixelVector.resize(dX);

	// loop through each row of the vector
	for(int i=0; i<pixelVector.size(); i++)
		// resize each row to the specified height
		pixelVector[i].resize(dY);
}

// This function saves the current state of the PpmImage object to a PPM file.
// It returns true if the file was successfully saved, and false otherwise.
// It opens the file with the name stored in the class's fileName member variable,
// and writes the PPM header information (version, dimensions, and maximum color value)
// followed by the RGB values of each pixel in row-major order.
// If the file fails to open or write, it returns false and prints an error message to cerr.
bool PpmImage::savePpmToFile() const 
{
	bool r_value = true;
	ofstream fout;
	fout.open(fileName);

	if(fout.is_open())
	{
		fout<<version<<endl;
		fout<<dX<<" "<<dY<<endl;
		fout<<max<<endl;

		for(int i=0; i<pixelVector.size(); i++)
		{
			for(int k=0; k<pixelVector[i].size(); k++)
			{
				fout<<pixelVector[i][k].getR()<<" ";
				fout<<pixelVector[i][k].getG()<<" ";
				fout<<pixelVector[i][k].getB()<<" ";
				fout<<"   ";
			}
			fout<<endl;
		}
	}
	else
	{
		r_value = false;
		cerr<<"Failed while saving the file!!"<<endl;
	}
	fout.close();

	return r_value;
}

// This function reads a ppm file from the given source file name and stores the image data in the
// given PpmImage object. It returns an integer value indicating the success of the operation, where
// 0 means failure and 1 means success.
// The function first checks if the file format is correct and the dimensions and color values are
// within the expected range. If everything is correct, it resizes the pixel vector of the destination
// object and sets the pixel values from the file. If any error occurs during the process, the function
// sets the fileFormatIsTrue flag to false and terminates. 
int read_ppm(const string source_ppm_file_name, PpmImage& destination_object)
{
	ifstream fin;	
	fin.open(source_ppm_file_name);
	string temp;
	int d1,d2,maxColor;
	vector<vector<Pixels> >& pV = destination_object.getVector();
	int _r, _g, _b; // i =0, k =0,m =0;
	bool fileFormatIsTrue = true;
	if(fin.is_open())
	{
		fin>>temp; // taking format
		if(temp =="P3") // we'll use this format in this project
			destination_object.setVersion(temp);
		else fileFormatIsTrue = false; 
		
		fin>>d1>>d2; // taking dimesions
		if(d1 <=_MAX_X_ && d2<=_MAX_Y_ && fileFormatIsTrue==true)
		{
			destination_object.setdX(d1);
			destination_object.setdY(d2);
		}
		else fileFormatIsTrue = false;
		fin>>maxColor; // taking max rgb value
		if(maxColor<=255 && fileFormatIsTrue == true)
			destination_object.setMax(maxColor);
		else fileFormatIsTrue = false;

		if(fileFormatIsTrue) // resizeing of the vector
			destination_object.resizeVector(); 
		else cout<<"file format is not true!! please check it"<<endl;

		if(fileFormatIsTrue)
		{

			for(int i=0;i<destination_object.getdX(); i++)
			{
				for(int k =0; k<destination_object.getdY(); k++)
				{
					fin>>_r>>_g>>_b;
					if( fileFormatIsTrue==true )
					{
						if(_r<0 ) _r = 0;
						else if(_r>255 ) _r = 255;
						if(_g<0 ) _g = 0;
						else if(_g>255 ) _g = 255;
						if(_b<0 ) _b = 0;
						else if(_b>255 ) _b = 255;
						pV[i][k].setR(_r);
						pV[i][k].setG(_g);
						pV[i][k].setB(_b);
					}
					else // the rg values are not in expected boundry (0-255) terminate!
					{
						fileFormatIsTrue = false;
						cout<<"the rgb values improper!! please check it!!"<<endl;
						break;
					}
				}
				if(!fileFormatIsTrue)
					break;
			}
		}

		fin.close();
	}
	else
	{
		cerr<<"error while opening the file !!"<<endl;
		fileFormatIsTrue = false;	
	}   
	if(!fileFormatIsTrue)
		return 0;
	else return 1;

}

// This function writes the data from a PpmImage object to a PPM file with the given file name.
// It returns 1 on success and 0 on failure.
int write_ppm(const string destination_ppm_file_name,  const PpmImage& source_object)
{
    bool r_value = true;
    ofstream fout;
    fout.open(destination_ppm_file_name); // Open the output file for writing.
    vector<vector<Pixels> > const &pV = source_object.getVector(); // Get the pixel data from the PpmImage object.

    if(fout.is_open()) // Check if the file was opened successfully.
    {
        fout<<source_object.getVersion()<<endl; // Write the PPM format.
        fout<<source_object.getdX()<<" "<<source_object.getdY()<<endl; // Write the dimensions.
        fout<<source_object.getMax()<<endl; // Write the maximum RGB value.

        // Write the pixel RGB values.
        for(int i=0; i<pV.size(); i++) 
        {
            for(int k=0; k<pV[i].size(); k++)
            {
                fout<<pV[i][k].getR()<<" ";
                fout<<pV[i][k].getG()<<" ";
                fout<<pV[i][k].getB()<<" ";
                fout<<"   ";
            }
            fout<<endl;
        }
        fout.close(); // Close the output file.
    }
    else // If the file could not be opened for writing, set r_value to false and print an error message.
    {
        r_value = false;
        cerr<<"Failed while saving the file!!"<<endl;
    }

    if(!r_value) // If r_value is false, return 0, indicating failure.
        return 0;
    else // If r_value is true, return 1, indicating success.
        return 1;

}

// This function swaps the specified color channels of a PpmImage object.
// The swap_choice parameter determines which channels to swap:
// 1 -> swap red and green channels
// 2 -> swap red and blue channels
// 3 -> swap green and blue channels
// If an invalid swap_choice value is given, the function returns 0 and prints an error message. Otherwise, it returns 1.
int swap_channels(PpmImage& image_object_to_be_modified, int swap_choice)
{
	int temp;
	if(swap_choice==1 ||swap_choice==2 || swap_choice==3 )
	{
		for(int i=0;i<image_object_to_be_modified.getdX(); i++)
		{
			for(int k=0;k<image_object_to_be_modified.getdY(); k++)
			{
				if(1==swap_choice) // if swap_choice is 1: swaps red and green
				{
					int& r = image_object_to_be_modified(i,k,1);			
					int& g = image_object_to_be_modified(i,k,2);
					temp = r; 		
					r=g;
					g = temp;
				}
				else if(2==swap_choice)// if swap_choice is 2: swaps red and blue
				{
					int& r = image_object_to_be_modified(i,k,1);			
					int& b = image_object_to_be_modified(i,k,3);
					temp = r; 		
					r=b;
					b = temp;
				}

				else if(3==swap_choice)// if swap_choice is 3: swaps green and blue
				{
					int& b = image_object_to_be_modified(i,k,3);			
					int& g = image_object_to_be_modified(i,k,2);
					temp = b; 		
					b=g;
					g = temp;
				}
			}
		}
		return 1;
	}
	else
		cerr<<"invalid swap choice !!"<<endl;	
	
	
	return 0;
}

// This function creates a copy of the input PpmImage object and sets all the RGB values to zero.
// Then, depending on the input color_choice, it sets the corresponding RGB value to the value of the same pixel in the original image.
// Finally, it returns the modified copy.
PpmImage single_color(const PpmImage& source, int color_choice)
{
	// Create a copy of the input PpmImage object
	PpmImage copy;
	copy = source;
	
	// Loop through each pixel in the image
	for(int i = 0; i<copy.getdX(); i++)
	{
		for(int k=0; k<copy.getdY(); k++)
		{
			// Get references to the RGB values of the pixel
			int &r = copy(i,k,1);
			int &g = copy(i,k,2);
			int &b = copy(i,k,3);
			
			// Set all RGB values to zero
			r = 0;
			g = 0;
			b = 0;
			
			// Depending on the input color_choice, set the corresponding RGB value to the value of the same pixel in the original image
			if(1==color_choice)
				r = source.pixelInfo(i,k,1);
			if(2==color_choice)
				g = source.pixelInfo(i,k,2);
			else if(3==color_choice)
				b = source.pixelInfo(i,k,3);
		}
	}

	// Return the modified copy
	return copy;
}

// This is the main function of the program.
int main(int argc, char const *argv[])
{
	// Declare and initialize variables
	int choice;
	string ppm_file_name1;
	string ppm_file_name2;
	string ppm_file_name3;
	PpmImage obj;
	string output;
	bool ArgumentsAreOke = true;

	// Check if there are enough arguments
	if(argc>2)
		choice = stoi(argv[1]);	  
	if(argc == 4 ){
		ppm_file_name1 = argv[2];	
		ppm_file_name2 = argv[3];	
	}
	else if(argc == 5 )
	{
		ppm_file_name1 = argv[2];	
		ppm_file_name2 = argv[3];
		ppm_file_name3 = argv[4];	
	}
	else 
	{
		cerr << "Wrong call!" << endl;
		ArgumentsAreOke = false;
	}
	
	// If the arguments are OK, execute the corresponding option based on the input choice
	if(ArgumentsAreOke){
		if(choice == 1)
		{
			if(argc == 5)
				test_addition(ppm_file_name1,ppm_file_name2,ppm_file_name3);
			else cerr << "Wrong call!" << endl;
		}
		else if(choice == 2)
		{
			if(argc == 5)
				test_subtraction(ppm_file_name1,ppm_file_name2,ppm_file_name3);
			else cerr << "Wrong call!" << endl;
		}
		else if(choice==3)
		{
			// Read the input image file into the obj PpmImage object
			read_ppm(ppm_file_name1, obj);	
			// Swap the red and blue channels in the obj object
			swap_channels(obj, 2);
			// Write the modified obj object to the output image file
			write_ppm(ppm_file_name2, obj);
		}
		else if(choice==4)
		{
			read_ppm(ppm_file_name1, obj);	
			swap_channels(obj, 3);
			write_ppm(ppm_file_name2, obj);
		}
		else if(choice==5)
		{
			read_ppm(ppm_file_name1, obj);	
			write_ppm(ppm_file_name2, single_color(obj, 1));
		}
		else if(choice==6)
		{
			read_ppm(ppm_file_name1, obj);	
			write_ppm(ppm_file_name2, single_color(obj, 2));
		}
		else if(choice==7)
		{
			read_ppm(ppm_file_name1, obj);
			write_ppm(ppm_file_name2, single_color(obj, 3));
		}
		else cerr<<"invalid option!!"<<endl;
	}

	return 0;
}
