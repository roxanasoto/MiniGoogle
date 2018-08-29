#include "CCloud.h"

CCloud::CCloud()
{
	palabra_actual = "";
	documento_actual = -1;
	archivo = NULL;
	ejecutando = false;
}

CCloud::CCloud(T_STRING ruta)
{
	palabra_actual = move(ruta);
	documento_actual = -1;
	archivo = NULL;
	ejecutando = false;
}
CCloud::~CCloud()
{
	
}
void CCloud::gen_doc(){

}

int CCloud::abrir_doc(T_STRING ruta)
{
	DIR *dir;
	struct dirent *ent;
	/*if ((dir = opendir ("/home/uburoxana/Documents/copia_git/MiniGoogle/Minigoogle_core/test")) != NULL) {
  	
  	closedir (dir);
	} else {
  	perror ("");
  	return EXIT_FAILURE;
	}*/

	string  sufix_text= "spanishText_";
	char buffer[1000];
	//string fin_archivo= "</doc>";

	if ((dir = opendir ("/home/uburoxana/Documents/copia_git/MiniGoogle/Minigoogle_core/raw.es")) != NULL) {
			while ((ent = readdir (dir)) != NULL) {
				
				archivo = fopen((ruta + ent->d_name).data(), "r");
				//archivo = fopen((ruta + sufix_text + to_string(ruta_inicio)+ "_" + to_string(ruta_final)).data(), "r");
				if (archivo==NULL)
			  	{
			    	//fputs ("fopen example",archivo);
			    	fclose (archivo);
			    	  	return -1;

			  	}
			  	else{
			  		
	  		
	    			//printf ("%s\n", ent->d_name);
	    			//puts("");
			  		while ( fgets (buffer , 1000 , archivo) != NULL ){
			  			
			  			if(buffer[0]=='<' && buffer[1]=='/'){
			  				//tercer caso
			  				fclose (archivo_destino);
			  				/*string error="error";
			  				puts(error.data());*/
			  			}
			  			else if(buffer[0]=='<' && buffer[1]=='d'){
			  				//primer caso
			  				int index=0;
				       		id=""; 
				       		titulo=""; 

				       		while(buffer[index]!='"')
				       		{
				       			index++;
				       		}
				       		index++;
				       		while(buffer[index]!='"')
				       		{
				       			id+=buffer[index++];
				       		}
				       		//puts(id.data());
							index++;
				       		while(buffer[index]!='"')
				       		{
				       			index++;
				       		}
				       		index++;
				       		while(buffer[index]!='"')
				       		{
				       			titulo+=buffer[index++];
				       		}
				       		//puts(titulo.data());
				       		string ruta_nueva="archivos_id/";

				       		archivo_destino = fopen((ruta_nueva + id + ".txt").data(), "w");
				       		fputs(id.data(),archivo_destino);
				       		fputs("\n",archivo_destino);
				       		fputs(titulo.data(),archivo_destino);
				       		fputs("\n",archivo_destino);


			  			}
			  			else{
			  				

				       		//segundo caso
			  				body="";
				       		//int index=0;
				       		body+=buffer;
				       		fputs(body.data(), archivo_destino);

			  			}

		  			}
  			}
		

		
	  			

	     	fclose (archivo);

	  	}
		


	}
	
  	return 0;

	
}

