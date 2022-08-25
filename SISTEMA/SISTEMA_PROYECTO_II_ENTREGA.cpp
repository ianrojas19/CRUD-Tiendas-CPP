#include<iostream>   //Bibliotecas Principales
#include<string.h>
#include<stdlib.h> 
#include<conio.h>    //Bibliotecas Secundarias
#include<windows.h>
#include<locale.h>   // Biblioteca de Idioma
using namespace std;

//Estructuras
struct user{
	char id[5];
	char nick[25];
	char password[25];
}user[3];
         
struct producto{
	int precio;
	int garantia;
	int stock;
	char cod[4];
	char name[100];
}producto[20];

struct cliente{
	char cedula[15];
	char nombrecmp[45];
	char direccion[100];
	char telefono[25];
	char email[25];
}cliente[20];

struct factura{
	int codFact;
	int precioun;
	int cantprod;
	int subtotal;
	char codprod[25];
	char nomclient[25];
	char nomprod[100];
}factura[21];

int main(){
	//Variables
	bool access,success,prodelim,error,errorpr,vercli,verclient,elimcli,foundfact,foundfactu,errorcant,usact,nofnd;
	int a, b, c, d, p, m, f, z, g, y, x, r, n, h, u, prods, i=0, s, v, q, reps=0, repes=0, regreso;
	int actuprodgarantia, actuprodstock, actuprodprecio, client=0, repescl=0, sistema1, factu, total=0,activo=0;
	int cantidad=0,repetis=0, registro=0, intentos=0, prod=0, sistema, rec=0, salir, prodfound, atemps=0, intentar, creg=0, copy=0;
	char actuclidireccion[110], actuclitelefono[25], actucliemail[25], desi[4];
	char actuprodname[100], idu1[5]="us1", idu2[5]="us2", idu3[5]="us3", noap[11]="NO APLICA"; 
	char clientefact[25], prodFact[25], fecha[30], hora[30], contin[25], admin[25], modific[25], confirm[15];
	char namepr[100], passpr[100], actu[100], buscprod[100], elimprod[100], elimcod[100], nomdelete[100]="\0", direccioncliente[100];
	char opcion= ' ', des= ' ', intento=' ', exit= ' ', buscli[15], busclient[15], buscliente[15], coddelete[10]="\0", nombrecliente[45];
	float IVA, DESC, totalfact;
	
	//Para que sirva la ñ porque el gringo diabetico que hizo c++ no le dio la perra gana añadirla.
	setlocale(LC_CTYPE, "Spanish"); 
	system("color f");  //Letras ak7
	
	do{
	//Bienvenida
		cout<<"\n\n\t\t\t\t     ~ WINSTON TECHNOLOGIES ~"; 
		cout<<"\n\n\t\t\tBienvenido al sistema, elije alguna de estas opciones: "<<endl;
		
	//Opciones
		cout<<"\n1. Registro"<<endl;			
		cout<<"\n2. Iniciar Sesion"<<endl;
		cout<<"\n3. Modificar Usuarios";			
		cout<<"\n\n4. Salir del Sistema";			
		cout<<"\n\nEleccion: "; cin>>opcion;
	
	//Eleccion
		switch(opcion){
	//Registro
		case '1':
			if(registro>=3){
				system("CLS");
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tCantidad maxima de registros alcanzada, se le redirigira a la pagina de inicio.";
				Sleep(2000); system("CLS");	regreso=1; break;  
			}
		
			else{
				for(b=0;b<=0;b++){
					fflush(stdin); system("CLS");
					cout<<"\n\n\t\t\t\t\t~ REGISTRO ~";	
					cout<<"\n\nRegistro #"<<registro+1<<endl; 
					switch(registro){
						case 0:
							cout<<"\n\nCodigo de Usuario asignado: "<<idu1;
						break;
						
						case 1:
							cout<<"\n\nCodigo de Usuario asignado: "<<idu2;
						break;
					
						case 2:
							cout<<"\n\nCodigo de Usuario asignado: "<<idu3;
						break;
					}
					
					cout<<"\n\n\nIngrese su nombre de usuario (minimo 4 caracteres): "; cin>>user[registro].nick;
					cout<<"\n\nIngrese su contraseña (minimo 4 caracteres): "; cin>>user[registro].password;
					
	//Prueba de repeticion
				for(c=0;c<=2;c++){
					if(strcmp(user[registro].nick,user[c].nick)==false){
						reps=reps+1;
					}
				}	
						
	//Si registrado
				if(reps==1 && strlen(user[registro].password)>=4 && strlen(user[registro].nick)>=4){
					system("CLS");	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tRegistro completado... Bienvenid@ "<<user[registro].nick<<"!"; 
					reps=0; registro=registro+1; regreso=1;	Sleep(1500); system("CLS");
					
	//Asignar las ids de usuario automaticamente
					switch(registro-1){
						case 0:
							strcpy(user[registro-1].id,idu1);
						break;
					
						case 1:
							strcpy(user[registro-1].id,idu2);
						break;
						
						case 2:
							strcpy(user[registro-1].id,idu3);
						break;
					}
				}

	//Si no registrado
				else{
					system("CLS");cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tCreacion de usuario invalido, intentelo nuevamente..."; 
					Sleep(1500); reps=reps=0; b=b-1; creg=creg+1;
				}
		
				if(creg==3){
					system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tLimite de intentos alcanzados, se le redirigira a la pagina principal."; 
					b=b+1; reps=0; regreso=1; Sleep(1500); creg=0;  
				}
			}
		}
		
		system("CLS");
		
		break;		
	
	//Inicio de Sesion	
		case '2':
		do{
			system("CLS"); 
			cout<<"\n\n\t\t\t\t     ~ INICIO DE SESION ~";fflush(stdin); usact=false;
			cout<<"\n\nIngrese su nombre de usuario: "; cin.getline(namepr,100);
			cout<<"\n\nIngrese su contraseña: "; cin>>passpr;
				
	//Validacion de usuario
			for(u=0;u<=3;u++){
				if(strcmp(namepr,user[u].nick)==false && strcmp(passpr,user[u].password)==false){
					system("CLS"); access=true; cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tAcceso concedido!"; 
					u=activo; usact=true; Sleep(1500); break;
				}
			}
		
			if(usact==false){
				system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tEl nombre de usuario o la contraseña son incorrectos, intentelo de nuevo...";
				Sleep(1200);system("CLS"); access=false; intentos=intentos+1;
			}
				
	//Validacion de intentos	
			if(intentos==3){
				system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tLimite de intentos alcanzados, se le redirigira a la pagina principal.";
				Sleep(1500); system("CLS"); access=true;
			}
		}
		
	//Redireccion a la pag principal si falla 3 veces su inicio de sesion.
		while(access==false);
		
		if(intentos==3){
			intentos=0; regreso=1; break; 
		}		 
		
	//Si inicia sesion correctamente
		system("CLS");intentos=0;
		
		do{
				
///////////////////////////////////////////////// GESTION DEL C R U D EMPRESARIAL ////////////////////////////////////////////////////////////////////////////		
			cout<<"\n\n\t\t\t\t     ~ WINSTON TECHNOLOGIES ~"<<endl;
			cout<<"\n\nSeleccione una opcion: ";
			cout<<"\n\n1. Gestionar productos";	
			cout<<"\n\n2. Gestionar clientes";
			cout<<"\n\n3. Generar factura";
			cout<<"\n\n4. Cerrar sesion";
			cout<<"\n\nEleccion: ";cin>>opcion; system("CLS");
			
			switch(opcion){
		 				
	/////////////////////////////////////////////        Gestionar PRODUCTOS             ////////////////////////////////////////////////////////////////////////
	
			case '1':
				do{
					cout<<"\n\n\t\t\t\t     ~ Gestion de Productos ~"<<endl;
					cout<<"\n\nSeleccione una opcion: ";
					cout<<"\n\n1. Crear producto";	
					cout<<"\n\n2. Actualizar producto";
					cout<<"\n\n3. Buscar producto";
					cout<<"\n\n4. Eliminar producto";
					cout<<"\n\n5. Salir de Gestion de Productos";
					cout<<"\n\nEleccion: ";cin>>opcion;
					system("CLS");
		
				switch(opcion){
	
	//Crear PRODUCTO
					case '1':
	//MENSAJE SI EL INVENTARIO ESTA LLENO 			
						if(prod>=20){
							system("CLS"); 
							cout<< "\n\n\n\n\n\n\n\n\n\n\n\t\tInventario lleno, elimine algun producto para acceder a esta opcion."; 
							Sleep(2000); system("CLS"); sistema=1; break;
						}
							
						for(a=0;a<=0;a++){
							system("CLS"); fflush(stdin); error=false;
							cout<<"\n\n\t\t\t\t     ~ Crear Producto ~";
							cout<<"\n\nProducto #"<<prod+1<<"                                                         Formato de Codigo: p00";
							cout<<"\n\nIngrese el Codigo de Producto: "; cin>>producto[prod].cod; strlwr(producto[prod].cod);fflush(stdin);
							cout<<"\n\nIngrese el Nombre del Producto: "; cin.getline(producto[prod].name,100); strupr(producto[prod].name);fflush(stdin);
							cout<<"\n\nIngrese la garantia del Producto (MESES): "; cin>>producto[prod].garantia;
					
						if(cin.fail()){
							cin.clear(); cin.ignore(100, '\n');
							error=true;
						}
					
						cout<<"\n\nIngrese la cantidad de Existencias: "; cin>>producto[prod].stock;
						
						if(cin.fail()){
							cin.clear(); cin.ignore(100, '\n');
							error=true;
						}
					
						cout<<"\n\nIngrese el PRECIO x UNIDAD del producto (COLONES): "; cin>>producto[prod].precio;
			
						if(cin.fail()){
							cin.clear(); cin.ignore(100, '\n');
							error=true;
						}
				
						for(b=0;b<=19;b++){
							if(strcmp(producto[prod].cod,producto[b].cod)==false){	
								repes=repes+1;			
							}
						}
					
		//ERROR SI YA EXISTE EL PRODUCTO O INTRODUCE UN NOMBRE VACIO			
						fflush(stdin);
						if(repes>=2 || strcmp(producto[prod].name," ")==false || error==true || strlen(producto[prod].cod)>=4 || strlen(producto[prod].cod)<3){
							error==false; system("CLS"); 	cout<<"\n\n\n\n\n\n\n\n\n\t\tError en la creacion del producto, desea intentarlo de nuevo?";
							cout<<"\n\n\t\t1. SI / 2. NO";
							cout<<"\n\n\t\tEleccion: ";cin>>intentar;
								
		//ELECCION SI QUIERE REINTENTAR LA CREACION DEL PRODUCTO				
							if(intentar==1){
								system("CLS");cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tHa elegido reintentar la creacion del producto..."; 
								Sleep(1700); a=a-1; repes=0;
								strcpy(producto[prod].cod,coddelete);
							}
					
							else{
								strcpy(producto[prod].cod,coddelete);
								system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tHa elegido cancelar la creacion del producto...";
								Sleep(1700); repes=0;
							}
						}
							
						else{
							system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tProducto creado correctamente!";
							Sleep(2000); prod=prod+1; repes=0; error==false;
						}
					}
		
					system("CLS"); sistema=1; repes=0;
					
					break;
			
	//Actualizar PRODUCTO	
					case '2':
						do{	
							system("CLS"); fflush(stdin);
							cout<<"\n\n\t\t\t\t     ~ Actualizar Producto ~                       ";
						
							cout<<"\n\n\nIngrese el codigo del producto que desea actualizar: "; cin>>actu; strlwr(actu);
							prodfound=false;
	
	//SI ENCUENTRA EL PRODUCTO EN LA LISTA DE PRODUCTOS
						for(c=0;c<=prod;c++){
							errorpr=false;
								
							if(strcmp(actu,producto[c].cod)==false){
								prodfound = true; rec=c;
	//Guarda los valores en auxiliares para mostrar las originales todas las veces que el usuario intente actualizar
								if(copy==0){
									strcpy(actuprodname,producto[c].name);
									actuprodgarantia=producto[c].garantia;
									actuprodstock=producto[c].stock;
									actuprodprecio=producto[c].precio;
								}	
	//DATOS ORIGINALS
							cout<<"\n\n\t\t\t\t\t  Valores INICIALES";fflush(stdin);	
							cout<<"\n\nCodigo del Producto: "<<actu;                          
							cout<<"\n\nNombre del Producto: "<<actuprodname;            
							cout<<"\n\nGarantia del Producto (MESES): "<<actuprodgarantia;        
							cout<<"\n\nCantidad de Existencias: "<<actuprodstock;  
							cout<<"\n\nPrecio x Unidad: "<<actuprodprecio<<" colones";
    //ACTUALIZACION DE LOS DATOS
							cout<<"\n\n\t\t\t\t\t  Valores NUEVOS";fflush(stdin);	
							cout<<"\n\nCodigo del Producto: "<<actu; fflush(stdin);
							cout<<"\n\nNuevo Nombre del Producto: "; cin.getline(producto[c].name,100); strupr(producto[c].name);
							cout<<"\nNueva Garantia del Producto (MESES): "; cin>>producto[c].garantia;

	//Limpia la variable para que no crashee y vuelva a ingresar el valor					
							if(cin.fail()){					
								cin.clear(); 
								cin.ignore(100, '\n');
								errorpr=true;
							}
						
							cout<<"\nNuevo Cantidad de Existencias: "; cin>>producto[c].stock;
							
							if(cin.fail()){					
								cin.clear(); 
								cin.ignore(100, '\n');
								errorpr=true;
							}
						
							cout<<"\nNuevo Precio x Unidad (COLONES): "; cin>>producto[c].precio;
						
							if(cin.fail()){					
								cin.clear(); 
								cin.ignore(100, '\n');
								errorpr=true;
							}
								
	//VERIFICAR SI LOS DATOS SON CORRECTOS
						if(errorpr==true || strlen(producto[c].name)==0){
							system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tLos valores ingresados son incorrectos, intentelo nuevamente...";
							Sleep(1500); c=c-1; system("CLS"); copy=copy+1;
						}
								
						else{
							break;
						}
					}
				
					else{
						prodfound=false;
					}
				}
							
	//FALLO EN LA BUSQUEDA DEL PRODUCTO
					if(prodfound==false){
						system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tEl codigo del producto ingresado es incorrecto, vuelva a intentarlo..."; 
						Sleep(1500); system("CLS"); prodfound=false; atemps= atemps + 1;
					}
						
					else{
						system("CLS");	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tEl producto ha sido actualizado correctamente!"; 
						atemps=0; Sleep(2000); prodfound=true; sistema=1; system("CLS"); copy=0;
					}
						
	//REDIRECCION POR INTENTOS FALLIDOS
					if(atemps==3){
						system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tHa realizado muchos intentos, desea seguir intentando?"; 
						cout<<"\n\n\n\t\t(S)i / (N)o: "; cin>>intento; 
					
						switch(intento){
							case 's':
								system("CLS");	atemps=0; cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tHa decido seguir intentando...";
								Sleep(2000); system("CLS"); prodfound=false;
							break;
							
							case 'S':
								system("CLS");	atemps=0; cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tHa decido seguir intentando...";
								Sleep(2000); system("CLS"); prodfound=false;
							break;
	
							case 'n':
								system("CLS");	atemps=0; cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tHa decido regresar al menu inicia...l"; 
								Sleep(2000); prodfound=true; sistema=1; system("CLS");
								
							case 'N':
								system("CLS");	atemps=0; cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tHa decido regresar al menu inicial..."; 
								Sleep(2000); prodfound=true; sistema=1; system("CLS");
							break;
			
							default:
								system("CLS");	atemps=0; cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tEleccion incorrecta, regresara al menu inicial"; 
								Sleep(2000); prodfound=true; sistema=1; system("CLS"); cin.clear(); cin.ignore(100, '\n');
							break;
						}
					}
				}		
				
				while(prodfound==false);
		
				break;
			
	//Buscar PRODUCTO		
		case '3':	
			system("CLS"); fflush(stdin);
			cout<<"\n\n\t\t\t\t     ~ Buscar Producto ~";
			cout<<"\n\n\nIngrese el codigo del producto que desea buscar: ";cin>>buscprod; strlwr(buscprod);fflush(stdin);
		
	//SI ENCUENTRA EL PRODUCTO EN LA LISTA DE PRODUCTOS
	 
			for(z=0;z<=prod;z++){
				if(strcmp(buscprod,producto[z].cod)==false){
					success=true;
		
	//IMPRESION DE LOS DETALLES DEL PRODUCTO ENCONTRADO			
					cout<<"\n\n\n\t\t\t\t-  Detalles del Producto  -                       ";	
					cout<<"\n\nCodigo del Producto: "<<buscprod;
					cout<<"\n\nNombre del Producto: "<<producto[z].name;	
					cout<<"\n\nGarantia del Producto (MESES): "<<producto[z].garantia;
					cout<<"\n\nCantidad de Existencias: "<<producto[z].stock;
					cout<<"\n\nPrecio x Unidad (COLONES): "<<producto[z].precio<<" colones";
				
					cout<<"\n\n\n\t\t\t  Presione cualquier tecla para salir..."; getch(); break;
				}	
			
				else{
					success=false;	
				}	
			}
			
	// SI NO ENCUENTRA EL PRODUCTO
			if(success==false){
				system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\t\tProducto no encontrado :(";
				cout<<"\n\n\n\t\tPresione cualquier tecla para salir..."; getch();
			}
		
			fflush(stdin); sistema=1; system("CLS");
			
			break;
				
	//Eliminar PRODUCTO		
		case '4':
			fflush(stdin);
			cout<<"\n\n\t\t\t\t     ~ Eliminar Producto ~"; prodelim=false;
		
			cout<<"\n\nIngrese el codigo del producto que desea eliminar: ";cin>>elimcod;

	// SI ENCUENTRA EL PRODUCTO INDICADO EN LA VARIABLE ELIMCOD
				for(y=0;y<=prod;y++){
					if(strcmp(elimcod,producto[y].cod)==false){
						prodelim=true; system("CLS");	
						cout<<"\n\n\n\n\n\n\n\n\n\t\tProducto encontrado... desea eliminar este producto del sistema?";
						cout<<"\n\n\n\t\t(S)i / (N)o: "; cin>>desi; strlwr(desi);
						
	// ASIGNA VALORES DE VACIO A LAS PROPIEDADES DEL PRODUCTO PARA ELIMINARLO DE LA ESTRUCTURA				
						if(strcmp(desi,"s")==false){
							strcpy(producto[y].cod,coddelete); prod=prod-1; system("CLS");		
							cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tProducto eliminado, presione cualquier tecla para salir..."; getch(); break;
						}
				
						else{
							system("CLS");	cout<<"\n\n\n\n\n\n\n\n\n\t\tEl producto no ha sido eliminado";
							cout<<"\n\n\n\t\tPresione cualquier tecla para salir..."; getch(); break;
						}
					}
				}
		
				if(prodelim==false){
					system("CLS"); cout<<"\n\n\n\n\n\n\n\n\t\tProducto no encontrado :(";
					cout<<"\n\n\n\t\tPresione cualquier tecla para salir..."; getch();
				}
			
			fflush(stdin); sistema=1; system("CLS");
		
		break;
			
		//Salir de CRUD DE PRODUCTOS	
			case '5':
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tSaliendo de Gestion de Productos...";
				Sleep(2000);system("CLS"); sistema=2; salir=1;
			break;	
			
		//Eleccion Incorrecta			
			default:
				system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tEleccion incorrecta, se le redirigira a la pantalla inicial..."; 
				Sleep(2000);system("CLS"); cin.clear(); cin.ignore(100, '\n'); sistema=1;
			break;
			}
		}
		
		while(sistema==1);fflush(stdin);
		
		break;
//////////////////////////////////////////////////////////////////  FINAL DEL CRUD DE PRODUCTOS	//////////////////////////////////////////////////////////////////	
	
	/////////////////////////////////////////////////////////////////// Gestionar CRUD clientes  /////////////////////////////////////////////////////////////////////////
		case '2':
			do{
				cout<<"\n\n\t\t\t\t     ~ Gestion de Clientes ~"<<endl;
				cout<<"\n\nSeleccione una opcion: ";
				cout<<"\n\n1. Crear cliente";	
				cout<<"\n\n2. Actualizar cliente";
				cout<<"\n\n3. Buscar cliente";
				cout<<"\n\n4. Eliminar cliente";
				cout<<"\n\n5. Salir de Gestion de Clientes";
				cout<<"\n\nEleccion: ";cin>>opcion;
				system("CLS");
						
					switch(opcion){
						
		//CREAR CLIENTE
						case '1':
							if(client>=20){
								system("CLS"); 
								cout<< "\n\n\n\n\n\n\n\n\n\n\n\t\tCartera de clientes llena, elimine algun cliente para acceder a esta opcion."; 
								Sleep(2000); system("CLS"); sistema1=1; break;
							}
								
							cout<<"\n\n\t\t\t\t     ~ Crear Cliente ~";fflush(stdin);
							cout<<"\n\nCliente #"<<client+1<<"\t\t\t\t\t\t\t\tFormato de Inexistencia: n/a"<<endl;
							cout<<"\n\nIngrese la cedula del Cliente: "; cin>>cliente[client].cedula; strlwr(cliente[client].cedula);fflush(stdin);
							cout<<"\n\nIngrese el nombre COMPLETO del Cliente: "; cin.getline(cliente[client].nombrecmp,45); fflush(stdin); strupr(cliente[client].nombrecmp);
							cout<<"\n\nIngrese la direccion de domicilo del Cliente: "; cin.getline(cliente[client].direccion,100); strupr(cliente[client].direccion);
							cout<<"\n\n*Ingrese el numero telefonico del Cliente: "; cin>>cliente[client].telefono; 
							cout<<"\n\n*Ingrese el correo electronico del Cliente: "; cin>>cliente[client].email;
							
							for(r=0;r<=19;r++){
								if(strcmp(cliente[client].cedula,cliente[r].cedula)==false){	
									repescl=repescl+1;			
								}
							}	
							
	//Cuando el usuario ingrese el codigo de inexsistencia se va a sustituir por el mensaje de default "NO APLICA"
							if(strcmp(cliente[client].telefono,"n/a")==false){
								strcpy(cliente[client].telefono,noap);
							}
							
							if(strcmp(cliente[client].email,"n/a")==false){
								strcpy(cliente[client].email,noap);
							}

	//Si cumple con todas las condiciones de creacion se creara el cliente
							if(strlen(cliente[client].nombrecmp)!=0 && strlen(cliente[client].direccion)!=0 && repescl==1){
								system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tCliente creado correctamente!";
								Sleep(1500); client=client+1; system("CLS"); repescl=0; sistema1=1; fflush(stdin);
							}

	//Si no los cumple (error)
							else{
								system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tError en la creacion del cliente, intentelo mas tarde...";
								Sleep(1500); system("CLS"); repescl=0; sistema1=1; fflush(stdin); cin.clear(); cin.ignore(100, '\n');
							}
							
						break;
						
		//ACTUALIZAR CLIENTE	
						case '2':
							fflush(stdin); verclient=false; 
							cout<<"\n\n\t\t\t\t     ~ Actualizar Cliente ~";
							cout<<"\n\n\nIngrese la cedula del cliente que desea actualizar: ";cin>>busclient; strlwr(busclient);
							
							for(m=0;m<=19;m++){
								if(strcmp(busclient,cliente[m].cedula)==false){
									
		//COPIA LOS VALORES INICIALES PARA QUE REGRESE LOS VALORES SI FALLA LA ACTUALIZACION.							
									strcpy(actuclidireccion,cliente[m].direccion);
									strcpy(actuclitelefono,cliente[m].telefono);
									strcpy(actucliemail,cliente[m].email);
									verclient=true;	fflush(stdin);
									
									cout<<"\n\n\n--> Formato de Inexistencia: n/a";
									
		//Muestra los valores actuales del cliente (antes de cualquier error de actualizacion)
									cout<<"\n\n\n\t\t\t\t\t -  Valores INICIALES del Cliente  -";
									cout<<"\n\nCedula del Cliente: "<<cliente[m].cedula;
									cout<<"\n\nNombre COMPLETO del Cliente: "<<cliente[m].nombrecmp;
									cout<<"\n\nDireccion de domicilo del Cliente: "<<cliente[m].direccion;
									cout<<"\n\n*Numero telefonico del Cliente: "<<cliente[m].telefono;
									cout<<"\n\n*Correo electronico del Cliente: "<<cliente[m].email;
		
		//Espacio de ingreso de los valores que actualizaremos
									cout<<"\n\n\n\t\t\t\t\t -  Valores NUEVOS del Cliente  -"; fflush(stdin);
									cout<<"\n\nCedula del Cliente: "<<cliente[m].cedula;
									cout<<"\n\nNombre COMPLETO del Cliente: "<<cliente[m].nombrecmp;
									cout<<"\n\nNueva direccion de domicilo del Cliente: ";cin.getline(cliente[m].direccion,100); strupr(cliente[client].direccion);
									cout<<"\n*Nuevo numero telefonico del Cliente: "; cin>>cliente[m].telefono;
									cout<<"\n*Nuevo correo electronico del Cliente: "; cin>>cliente[m].email;
									
	//Como en la creacion del cliente, si el cliente no posee una caracteristica NULL, se ingresa el codigo de inexistencia
									if(strcmp(cliente[m].telefono,"n/a")==false){
										strcpy(cliente[m].telefono,noap);
									}
									
									if(strcmp(cliente[m].email,"n/a")==false){
										strcpy(cliente[m].email,noap);
									}
	
	//Si cumple con todos los requisitos para actualizarse
									if(strlen(cliente[m].direccion)!=0 && strlen(cliente[m].telefono)!=0 && strlen(cliente[m].email)!=0){
										system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tCliente actualizado correctamente!";
										Sleep(1500); sistema1=1; fflush(stdin); 
									}
	
	//Si no las cumple (error)
									else{
										system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tError en la actualizacion del cliente, intentelo mas tarde...";
										strcpy(cliente[m].direccion,actuclidireccion);
										strcpy(cliente[m].telefono,actuclitelefono);
										strcpy(cliente[m].email,actucliemail);
										Sleep(1500); sistema1=1; fflush(stdin); 
									}
									
									break;
								}
							}
	
	//Si no existe(no ha sido creado) se le indica en el mensaje a continuacion
							if(verclient==false){
								system("CLS"); cout<<"\n\n\n\n\n\n\n\n\t\tCliente no encontrado :(";
								cout<<"\n\n\n\t\tPresione cualquier tecla para salir..."; getch(); sistema1=1;
							}
							
							system("CLS");
							
						break;
						
						case '3':
							cout<<"\n\n\t\t\t\t     ~ Buscar Cliente ~";fflush(stdin); vercli=false;
							cout<<"\n\n\nIngrese la cedula del cliente que desea buscar: ";cin>>buscli; strlwr(buscli);
	
		//Busca al cliente segun el codigo que hayamos ingresado
							for(n=0;n<=19;n++){
								if(strcmp(buscli,cliente[n].cedula)==false){
									cout<<"\n\n\n\t\t\t\t\t -  Detalles del Cliente  -"; vercli=true;	
									cout<<"\n\nCedula del Cliente: "<<cliente[n].cedula;
									cout<<"\n\nNombre COMPLETO del Cliente: "<<cliente[n].nombrecmp;
									cout<<"\n\nDireccion de domicilo del Cliente: "<<cliente[n].direccion;
									cout<<"\n\nNumero telefonico del Cliente: "<<cliente[n].telefono;
									cout<<"\n\nCorreo electronico del Cliente: "<<cliente[n].email;
									cout<<"\n\n\n\t\t\t\t    Presione cualquier tecla para salir"; getch(); sistema1=1; break; 
								}
							}
	
	//Si no lo encuentra(no ha sido creado)
							if(vercli==false){
								system("CLS"); cout<<"\n\n\n\n\n\n\n\n\t\tCliente no encontrado :(";
								cout<<"\n\n\n\t\tPresione cualquier tecla para salir..."; getch(); sistema1=1;
							}
							
							system("CLS");
							
						break;
						
						case '4':
							cout<<"\n\n\t\t\t\t     ~ Eliminar Cliente ~"; elimcli=false;
						
							cout<<"\n\n\nIngrese la cedula del cliente que desea eliminar: ";cin>>buscliente; strlwr(buscliente);
							
	//Busca al cliente en la estructura
							for(h=0;h<=19;h++){
								if(strcmp(buscli,cliente[h].cedula)==false){
									elimcli=true;	
									cout<<"\n\nCliente encontrado, para eliminarlo del sistem, ingrese nuevamente la cedula del cliente para confirmar la accion...";
									cout<<"\n\n\nConfirmacion: "; cin>>confirm; system("CLS");
									
	//Si confirma la creacion del usuario	
									if(strcmp(buscliente,confirm)==false){
										strcpy(cliente[h].cedula,coddelete); client=client-1; system("CLS");
										cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tCliente eliminado correctamente, presione cualquier tecla para salir...";	getch(); 
										sistema1=1; break; 
									}
	
	//Si introduce un codigo de cliente diferente al que se desea eliminar-
									else{
										cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tEl cliente no ha sido eliminado, intentelo mas tarde..."; 
										Sleep(2000); sistema1=1; break; 
									}
								}
							}
	
	//Si no lo encuentra(no ha sido creado)
							if(elimcli==false){
								system("CLS"); cout<<"\n\n\n\n\n\n\n\n\t\tCliente no encontrado :(";
								cout<<"\n\n\n\t\tPresione cualquier tecla para salir..."; getch(); sistema1=1;
							}
							
							system("CLS");
							
						break;
						
	//Salida del CRUD de Clientes
						case '5':
							cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tSaliendo de Gestion de Clientes...";
							Sleep(2000);system("CLS"); sistema1=2; salir=1;
						break;
						
						default:
							cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tEleccion incorrecta, se le redirigira a la pantalla inicial."; 
							Sleep(2000);system("CLS"); cin.clear(); cin.ignore(100, '\n'); sistema1=1;
						break;				
					}
			}
			
			while(sistema1==1);
			
		break;
	///////////////////////////////////////////////////////////////////// Final de CRUD CLIENTES /////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////// Generar FACTURA /////////////////////////////////////////////////////////////////////////
		case '3':
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tBIENVENIDO AL SISTEMA DE FACTURACIÓN DE 'WINSTON TECHNOLOGIES'.";fflush(stdin);
			
			cout<<"\n\n\t\tPor favor proceda a tocar una tecla y seguir las instrucciones."; getch(); system("CLS"); factu=1;                    
			
	//Pregunta la cedula del Cliente al que le estamos generando la compra
			system("CLS"); cout<<"\n\n\t\t\t\t     ~ Generar Factura ~";
			
			cout<<"\n\nIngrese Cedula de Cliente: "; cin>>clientefact;
				
			foundfactu=false;
				
	//Busca al cliente en su respectiva estructura
				for(s=0;s<=19;s++){
					if(strcmp(clientefact,cliente[s].cedula)==false){
						foundfactu=true; system("CLS");
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tCliente encontrado!";
						strcpy(nombrecliente,cliente[s].nombrecmp); strcpy(direccioncliente,cliente[s].direccion); Sleep(2000); system("CLS"); break;
					}
				}
				
	//Si no lo encuentra(no ha sido creado)
				if(foundfactu==false){
					system("CLS");cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tCliente inexistente, no se podra generar la factura..."; 
					Sleep(2000); salir=1; system("CLS"); break; 
				}
				
	//Empieza el ingreso de los productos que va a comprar el cliente
				while(factu==1){
	
	//Le da las opciones al ususario para que adjunte otro producto o finalize la compra e imprimir la factura
				system("CLS"); cout<<"\n\n\t\t\t\t     ~ Compra de Productos ~";
				cout<<"\n\n---> Opciones: 1. Adjuntar Producto / 2. Finalizar compra";
			
				foundfact=false;
	
	//Pide al usuario el codigo del producto
				cout<<"\n\nIngrese el Codigo del producto: "; cin>>prodFact; fflush(stdin);
				
	//Busca al producto en su respectiva estructura			
				for(x=0;x<=19;x++){
					if(strcmp(prodFact,producto[x].cod)==false){
						do{
	
	//Copia los valores de la estructura que pertenece el producto para insertarlos en la estructura FACTURA
							strcpy(factura[i].codprod,producto[x].cod);
							strcpy(factura[i].nomprod,producto[x].name);
							factura[i].precioun=producto[x].precio;
							fflush(stdin);
	
	//Le muestra los detalles del producto y le pregunta la cantidad del producto que desea comprar
							cout<<"\n\n==========================="; foundfact=true;
							cout<<"\n\nCodigo del producto: "<<factura[i].codprod;
						
							cout<<"\n\nNombre del producto: "<<factura[i].nomprod;
							
							cout<<"\n\nPrecio x Unidad: "<<producto[x].precio;
							
							cout<<"\n\nCantidad de compra: "; cin>>cantidad;
							cout<<"\n==========================="; 
	
	//Si mete algun caracter que no sea un numero o una cantidad mayor a la cantidad de existencias, falla.
							if(cin.fail() || producto[x].stock-cantidad<0){
								cin.clear();cin.ignore(100, '\n'); errorcant=true; system("CLS");
								cout<<"\n\n\n\n\n\n\n\t\tError de valores detectado...";fflush(stdin);
								
								cout<<"\n\n\t\tRazones: Datos incorrectos / Cantidad insuficiente de existencias del producto.";
							
								cout<<"\n\n\t\tDesea volver a ingresarlo al sistema? (S)i / (N)o, ingresar otro producto: "; cin>>contin; 
								system("CLS");
	
	//Si quiere ingresar otra cantidad
								if(strcmp(contin,"S")==false || strcmp(contin,"s")==false){
									system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tReintentara la compra del producto."; 
									Sleep(2000); system("CLS"); errorcant=true;
								}
								
	//Si quiere ingresar otro producto
								else{
									system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tNo se reintentara la compra del producto."; 
									Sleep(2000); system("CLS"); errorcant=false; factu=1;
								}
							}
	
	//Si no falla
							else{
								cout<<"\n\nProducto ingresado correctamente!";
								errorcant=false; factura[i].cantprod=cantidad;
								total=total+(producto[x].precio*cantidad); i=i+1;
							
								cout<<"\n\nOpcion: "; cin>>factu; 
							}
						}
						
						while(errorcant==true);
						
						break;
					}
				}
				
	////Si no existe el producto(no ha sido creado)
				if(foundfact==false){
					cout<<"\n\nProducto inexistente :("; 
					cout<<"\n\nOpcion: "; cin>>factu; fflush(stdin);
				}
				
				system("CLS");
				
			}
	//Hace las operaciones para generar los valores de IVA y Descuento respectivamente
			IVA=total*0.12;
			
			DESC=total*0.04;
			
			totalfact=total+IVA-DESC;
			
	//Asigna el numero de factura que estamos generando (empieza de 0 y aumentara mientras vayamos haciendo facturas)
			factura[1].codFact=factura[1].codFact+1; system("CLS"); fflush(stdin);
				
	//Factura generada con los datos introducidos
			cout<<"\n\n\t\t\t\t                FACTURA ";fflush(stdin);
			
			cout<<"\n\n\t\t=======================================================================";
		
			cout<<"\n\n\t\t\t\t                WINSTON TECHNOLOGIES";
		
			cout<<"\n\n\t\t\t\t                    2552 - 1064";
		
			cout<<"\n\n\t\t=======================================================================";
		
			cout<<"\n\n\t\t\tId Fact: "<<factura[1].codFact<<"\t\t\t\tFecha: "; cin>>fecha; fflush(stdin);
 		
		 	cout<<"\n\n\t\t\tCajero: "<<user[activo].nick<<"\t\t\t\tHora: "; cin>>hora;
 		
		 	cout<<"\n\n\t\t\tCedula del Cliente: "<<clientefact;
			 
			cout<<"\n\n\n\t\t\tNombre del Cliente: "<<nombrecliente; 
			
			cout<<"\n\n\n\t\t\tDireccion del Cliente: "<<direccioncliente;
 		
		 	cout<<"\n\n\t\t=======================================================================";
 			
			 for(prods=0;prods<=i-1;prods++){
 				cout<<"\n\n\n\t\t\tCodigo del producto: "<<factura[prods].codprod;
			
				cout<<"\n\n\t\t\tNombre del producto: "<<factura[prods].nomprod;
			
				cout<<"\n\n\t\t\tPrecio x Unidad: "<<factura[prods].precioun<<" colones";
			
				cout<<"\n\n\t\t\tCantidad de compra: "<<factura[prods].cantprod<<endl<<endl;
				
				for(q=0;q<=20;q++){
					if(strcmp(factura[prods].codprod,producto[q].cod)==false){
						producto[q].stock=producto[q].stock-factura[prods].cantprod;
						fflush(stdin);
					}
				}
			}
			cout<<"\n\n\t\t=======================================================================";
			
			cout<<"\n\n\t\t\tSubtotal:                                   "<<total<<" colones"; 
			
			cout<<"\n\n\t\t\tIVA:                                        "<<IVA<<" colones";
			
			cout<<"\n\n\t\t\tDescuento:                                  "<<DESC<<" colones";
			
			cout<<"\n\n\t\t\tTOTAL:                                      "<<totalfact<<" colones";
			
			cout<<"\n\n\t\t=======================================================================";
			
			cout<<"\n\n\t\t\tFactura conforme lo establecido por la resolucion No DGT-R-4"; 
			
			cout<<"\n\n\n\t\t\tPresione cualquier tecla para salir..."; getch(); 
			
			system("CLS"); fflush(stdin); i=0; salir=1; total=0; IVA=0; DESC=0; totalfact=0;
			
		break;
	///////////////////////////////////////////////////////////////////// FINAL DE GENERAR FACTURA //////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////// Cerrar sesion /////////////////////////////////////////////////////////////////////////////		
		case '4':
			salir=2;
		break;
		
	//Alguna otra estupidez que elija
		default:
			system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tEleccion incorrecta, se le redirigira a la pantalla inicial."; 
			Sleep(2000);system("CLS"); cin.clear(); cin.ignore(100, '\n'); salir=1;
		break;
		
			}
		}
		
		while(salir==1);
	
		system("CLS");cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tCierre de sesion exitoso..."; Sleep(2000); system("CLS");
	
		regreso=1;
	
		break;	
		
////////////////////////////////////////////////////// FIN DE GESTION DE C R U D EMPRESARIAL /////////////////////////////////////////////////////////////////////
					
	
		case '3':
			system("CLS"); cout<<"\n\n\t\t\t\t     ~ Modificar Usuarios ~"; nofnd=false;
			cout<<"\n\nPara poder modificar a los usuarios, ingrese la contraseña de administrador...";
			cout<<"\n\nContraseña: "; cin>>admin;
			
	//Compara la contraseña que ingresa el usuario con la contraseña de administrador
			if(strcmp(admin,"191004")==false){
				
	//Si la acierta se le da acesso al modificar a los usuarios
				system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tAcceso concedido!"; Sleep(2000); system("CLS");
				cout<<"\n\n\t\t\t\t     ~ Modificar Usuarios ~";
				cout<<"\n\nIngrese el Codigo del usuario que desea modificar: ";cin>>modific;
				
	//Recorre la estructura user para encontrar el codigo de usuario que ingreso el usuario para modificar
				for(int md=0;md<=20;md++){
					if(strcmp(user[md].id, modific)==false){
						cout<<"\n\nCodigo de Usuario: "<<user[md].id; nofnd=true;
						cout<<"\n\n\nIngrese el nuevo nombre de usuario (minimo 4 caracteres): "; cin>>user[md].nick;
						cout<<"\n\nIngrese la nueva contraseña (minimo 4 caracteres): "; cin>>user[md].password;
	
	//Recorre el valor de NICK en la estructura USER para probar si ya existe el nombre de usuario que ingresorá al sistema
						for(int cc=0;cc<=3;cc++){
							if(strcmp(user[md].nick,user[cc].nick)==false){
								repetis=repetis+1;
							}
						}	
						
	//Si cumple con todas las condiciones de modificacion
						if(repetis==1 && strlen(user[md].password)>=4 && strlen(user[md].nick)>=4){
							system("CLS");	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tModificacion completa... Bienvenid@ "<<user[md].nick<<"!"; 
							repetis=0; Sleep(1500); system("CLS"); break;
						}
	
	//Si no las cumple, fallará	
						else{
							system("CLS");cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tModificacion de usuario invalida, intentelo nuevamente..."; 
							Sleep(1500); repetis=repetis=0; md=md-1;
						}
					}
				}
				
				if(nofnd==false){
					system("CLS"); cout<<"\n\n\n\n\n\n\n\n\t\tUsuario no encontrado :(";
					cout<<"\n\n\n\t\tPresione cualquier tecla para salir..."; getch(); system("CLS");
				}
			}
	
	//Si no acierta la contraseña de administrador
			else{
				system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tAcceso denegado :("; Sleep(2000); system("CLS");
			}
		
			regreso=1;
			
		break;
		
	//Salir del SISTEMA
		case '4':
			regreso=2;
		break;
						
		default:
			system("CLS"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tEleccion incorrecta, se le redirigira a la pantalla principal."; 
			Sleep(2000);system("CLS"); cin.clear(); cin.ignore(100, '\n'); regreso=1;
		break;
		}
	}	

	// CUANDO FINALIZE EL SISTEMA POR COMPLETO Y YA NO SE OCUPEN REALIZAR MAS PROCESOS
		
		while(regreso==1);-
	
		system("CLS");

		cout<<"\n\n\t\t\t\t\t~ WINSTON TECHNOLOGIES ~"<<endl;
	
		cout<<"\n\n\n\n                                      Proceso finalizado con exito!"<<endl<<endl<<endl<<endl;
	
		return 0;
} 
