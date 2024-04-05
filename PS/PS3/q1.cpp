#include <iostream>

using namespace std;

class HotDogStand
{
    private:
        static int total_sold;
        int id_number;
        int sold_number;

    public:
       
        HotDogStand(int id, int sold)
        {
            id_number = id;
            sold_number = sold;
        }
        
        void JustSold()
        {
            sold_number += 1;
            total_sold += 1;
        }

        int get_id()
        {
            return id_number;
        }

        int get_num_sold()
        {
            return sold_number;
        }

        static int get_total_sold()
        {
            return total_sold;
        }
};

/* Initializing static variable */
int HotDogStand::total_sold = 0;

/* Main function */
int main()
{
    /* Test our code with three hot dog stands */
    HotDogStand s1(1,0), s2(2,0), s3(3,0);

    /* Updating items sold */
    s1.JustSold();
    s2.JustSold();
    s1.JustSold();

    /* Printing current status */
    cout << "Stand " << s1.get_id() << " sold " << s1.get_num_sold() << endl;
    cout << "Stand " << s2.get_id() << " sold " << s2.get_num_sold() << endl;
    cout << "Stand " << s3.get_id() << " sold " << s3.get_num_sold() << endl;

    /* Printing total sold */
    cout << endl << "Total sold = " << s1.get_total_sold() << endl;
    cout << endl;

    /* Updating items sold */
    s3.JustSold();
    s1.JustSold();

    /* Printing current status */
    cout << "Stand " << s1.get_id() << " sold " << s1.get_num_sold() << endl;
    cout << "Stand " << s2.get_id() << " sold " << s2.get_num_sold() << endl;
    cout << "Stand " << s3.get_id() << " sold " << s3.get_num_sold() << endl;

    /* Printing total sold */
    cout << endl << "Total sold = " << s1.get_total_sold() << endl;

    return 0;
}
