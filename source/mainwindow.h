#ifndef MAINWINDOW_H
#define MAINWINDOW_H

# include <iostream>
# include <cstdlib>
# include <string>
# include <vector>
# include <algorithm>
# include <cmath>
#include <QMainWindow>


using namespace std;


class conversion
{
    private:
        struct node				// for the 64-bit input box
        {
            vector <int> data;
            node* next;
        };

        node* head;
        node* cur;
        node* temp;

        vector <int> B_key;			// original 56-bit key

        struct key_node
        {
            int index;
            vector <int> rkey;		// stroing 19 48-bit keys
            key_node* next;
        };

        key_node* key_head;

        string EncryptedText;			// stores data in reverse order
        string DecryptedText;           // stoers the decrypted text

    public:
        conversion();
        void text_binary(string input);
        void encrypted_binary(string input);    // convert encrypted text into binary
        void key_binary(string key);
        void IP1();				// initial permutation
        void IP2();				// final permutation
        void PC1();				// permutates the key
        void PC2();				// form 16 56-bit keys
        void PC2_con();            		// covert 56-bit to 48-bit
        void E();				// Doing the main function for Encrption
        void D();				// Doing the main function for Decrption
        void swap_key();			// reversing the order of the keys
        void S(vector <int> &R);		// converting R 48-bit into 32-bit
        void binary_6();			// converting 64-bit into 6-bit box and printing it
        void print_EncryptedText(std::string &output);		// Printing the encrypted text
        void print_DecryptedText(std::string &output);		// Printing the deencrypted text
};

class AesClass
{
private:
    struct node
    {
        int data[4][4];
        node* next;
    };

    node* head;
    node* temp;

     struct key_node
    {
        int rkey[4][4];
        key_node* next;
    };

    key_node* keyhead;
    string Encryption;
    string Decryption;


public:
    AesClass();
    void text_to_node(string input);			// storing the input into the linked list
    void key_to_node(string input);				// storing the key into the first node of key's linked list
    void cipher_to_node(string input);			// storing the cipher into linked list
    void round_keys();					// making 10 new keys from the given key
    void mainRounds();					// the main 9 rounds that take place
    void binary_6();					// convert the hexadecimal into binary and map
    void Decrypted(string &output);				// store the text in the output
    void Encrypted(string &output);				// stores the text in output

    void reverse_keys();					// reverse the order of the keyes
};






namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
