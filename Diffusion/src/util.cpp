#include <iostream>
#include <fstream>
#include <iomanip>
#include "../include/util.h"

using namespace std;

void ecrit(const Eigen::VectorXf &uold, const float ug0, const float ud0, const std::string &filename) {

    std::ofstream my_file;

    my_file.open(filename, ios::app);
    // Verification de la connexion du fichier au flot my_file
    if (! my_file) {
      cerr << "erreur ouverture du fichier " << filename;
      exit(EXIT_FAILURE);
    }


    
    my_file << ug0 << " ";
    
    for (int i=0; i < uold.size(); i++) {
      my_file << uold(i) << " ";
    }
    
    my_file << ud0;
    my_file << endl;

    my_file.close();
}

void ecrit_entete(const Eigen::VectorXf &uold, const float nt, const float dx, const float dt, const float alpha, const std::string &filename) {

    ofstream my_file;

    my_file.open(filename);
    // Verification de la connexion du fichier au flot my_file
    if (! my_file) {
      cerr << "erreur ouverture du fichier " << filename;
      exit(EXIT_FAILURE);
    }

    // entete d'une ligne
    my_file << "# " << " " << uold.size() + 2 << " " << nt << " " << dx << " " << dt << " " << alpha << endl;


 

    my_file.close();
}
