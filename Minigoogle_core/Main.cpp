#include "CCloud.h"
#include "CCloud.cpp"
//#include "ICloud.h"
#include "DataTypes.h"

using namespace std;
int main(int argc, char* argv[]) {
	
	string ruta="raw.es/";
	CCloud nube;
	int a= nube.abrir_doc(ruta);
	cout<<a;
	return a;
}