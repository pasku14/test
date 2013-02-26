/*
 * PRÁCTICA 2. 
 * CIFRADO RC4.
 * FERNANDO CIFUENTES GONZALEZ - ALU4147.
 * 
*/

#include <iostream>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////
void intro_mensaje(vector <int> &mensaje){
	
	int tamano = 0;
	cout << " -- MENSAJE -- " << endl << endl;
	cout << "Introduzca tamano del mensaje: ";
	cin >> tamano;
	mensaje.resize(tamano);
	
	for(unsigned i = 0; i < mensaje.size(); i++){
		cout << "Introduzca " << i+1 << " mensaje: ";
		cin >> mensaje[i];
	}
}
////////////////////////////////////////////////////////////////////////
void intro_semilla(vector<int> &semilla){
	
	int tamano = 0;
	cout << "\n -- CLAVE -- " << endl << endl;
	cout << "Introduzca tamano clave: ";
	cin >> tamano;
	semilla.resize(tamano);
	
	for(unsigned i = 0; i<semilla.size();i++){
		cout << "Introduzca " << i+1 <<" clave: ";
		cin >> semilla[i];
	}	
}
////////////////////////////////////////////////////////////////////////
void KSA(vector<int>&K, vector<int>&S, vector<int>semilla){

	S.resize(256);
	K.resize(256);
	int j = 0;
	
	for (unsigned i = 0; i < S.size(); i++){
		S[i]=i;
		K[i]=semilla[i % semilla.size()];
	}
	
	for (unsigned i = 0; i < S.size(); i++){
		j =(j + S[i] + K[i]) % 256;
		swap(S[i],S[j]);
	}

}
////////////////////////////////////////////////////////////////////////
void PRGA(vector<int>S,vector<int>mensaje,vector<int>&mensaje_cifrado){
	
	int i = 0;
	int j = 0;
	int t = 0;

	for (unsigned k = 0; k < mensaje.size(); k++){
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		swap(S[i],S[j]);
		t = (S[i] + S[j]) % 256;
		mensaje_cifrado.push_back(S[t] xor mensaje[k]);
	}
}
////////////////////////////////////////////////////////////////////////		
void binario(int n){
	if (n !=0){
		binario(n/2);
		cout<< n % 2;
	}
}
////////////////////////////////////////////////////////////////////////
void convertir (vector <int> mensaje_cifrado){
	
	cout << "\n -- MENSAJE CIFRADO -- " << endl << endl;
	for (unsigned i = 0 ; i < mensaje_cifrado.size(); i++){
		binario(mensaje_cifrado[i]);
		cout << " ---- " << mensaje_cifrado[i]; 
		cout << endl;
	}
}	
////////////////////////////////////////////////////////////////////////			
int main(){

	vector <int> mensaje;
	vector <int> sem;
	vector <int> mensaje_cifrado;
	vector <int> K;
	vector <int> S;
	intro_mensaje(mensaje);
	intro_semilla(sem);
	KSA(K,S,sem);
	PRGA(S,mensaje,mensaje_cifrado);
	convertir(mensaje_cifrado);
	return 0;
}
