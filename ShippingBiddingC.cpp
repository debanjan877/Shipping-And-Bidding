#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include"headers\Globals.h"
#include"headers\BidInfo.h"
#include"headers\ShipInfo.h"
#include"headers\File.h"
 using namespace std;
 /* Non Static Functions */
 BidInfo::BidInfo()
{
  	_id=_shipItemId=_shipperId=_timeReqDays=_bidAmount=0;
}
unsigned long BidInfo::getId(){
	return_id;
}
unsigned long BidInfo::getShipItemId(){
	return _shipItemId;
}
void BidInfo::displayDetails(){
	cout<<"\n\tId: "<<_id;
	cout<<"\n\tAmount: "<<_bidAmount;
	cout<<"\n\tTime Required: "<<_time ReqDAys<<" days";
	cout<<endl;
}
void BidInfo::displayAsRow(){
	cout<<_id;
	cout<<"\t"<<_shipItemId;
	cout<<"\t"<<_shipperId;
	cout<<"\t"<<_bidAmount;
	cout<<"\t"<<_timeReqDays;
	cout<<endl;
}

void BidInfo::accept(){
	ShipInfo*shipInfo=File<ShipInfo>::find(SHIPINFO_FILE,_shipItenId);
	if(shipInfo!=NULL){
		shipInfo>setWonBy(_shipperId);
	}
}
/* Static Functions */
BidInfo*BidInfo::newEntry(unsigned long shipperId,unsigned long shipItemId){
	BidInfo* temp=new BidInfo();
	temp->_id=::newId();
	temp->_shipperId=shipperId;
	temp->_shipItemId=shipItemId;
if(File<BidInfo>::find(BIDINFO_FILE,temp->_id)!=NULL){
	cout<<"Internal error.Please retry.";
		system('cls");
	return BidInfo::newEntry(shipperId,shipItemId);
}
	cout<<"\n\tTime Required(days): ";
	cin>>temp->_timeReqDays;
	cout<<"\n\tamount: ";
	cin>>temp->_bidAmount;
	if(::canProceed()==1){
		File<BidInfo>::insert(BIDINFO_FILE,temp);
		return temp;
	}
	else{
		return NULL;
	}
}
void BidInfo::displayColumns(){
	cout<<"Id";
	cout<<"\t"<<"Ship Item Id";
	cout<<"\t"<<"Shipper Id";
	cout<<"\t"<<"Bid Amount";
	cout<<"\t"<<"Time Allocated (days)";
	cout<<endl;
	cout<<"----------------------------------------------------------------";
	cout<<endl;
}
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include"headers\Globals.h"
#include"headers\Contact.h"
#include"headers\ShipInfo.h"
#include"headers\File.h"
using namespace std;
/* Non Static Functions */
ShipInfo::ShipInfo(){
	_id=_customerId=_wonByShipperId=0;
	strcpy(_description,"");
	strcpy(_destinationLocation,"");
	strcpy(_status,"");
	_width=_height=_depth=_weight=_maxAmount=_maxDaysToTransport;
}
unsigned long ShipInfo::getCustomerId(){
	return_customerId;
}
unsigned long ShipInfo::getWonByShipperId(){
	return_wonByShipperId;
}
const char* ShipInfo::getStatus(){
	return_satus;
}
void ShipInfo::close(){
	if(::canProceed()){
		stcpy(_status,"Closed");
		File<ShipInfo>::update(SHIPINFO_FILE,this);
	}
}
void ShipInfo::setWonBy(unsigned long shipperId){
	if(::canProceed()){
		strcpy(_status,"Accepted");
		_wonByShipperId=shipperId;
		File<ShipInfo>::update(SHIPINFO_FILE,this);
	}
}
void ShipInfo::displayDetails(){
	cout<<"\n\tId: "<<_id;
	cout<<"\n\tCustomer Id: "<<_wonbyShipperId;
	cout<<"\n\tDescription: "<<_description;
	cout<<"\n\tLocation To: "<<_destinationLocation;
	cout<<"\n\tLocation From: "<<_sourceLocation;
	cout<<"\n\tWidth: "<<_width;
	cout<<"\n\tHeight: "<<_height;
	cout<<"\n\tDepth: "<<_dept;
	cout<<"\n\tweight: "<<_weight;
	cout<<"\n\tMax Bid: "<<_maxAmount;
	cout<<"\n\tMax Days: "<<_maxDaysToTransport;
	cout<<"\n\tCreated On: "<<ctime(&_createdOn);
	cout<<"\n\tExpire On:<<ctime(&_expireOn);
	cout<<"\n\tStatus: "<<_status;
	cout<<endl;
}
void ShipInfo::displayAsRow(){
	cout<<_id;
	cout<<"\t"<<_status;
	cout<<"\t"<<_sourceLocation;
	cout<<"\t"<<_destinationLocation;
	cout<<"\t"<<ctime(&_createdOn);
	cout<<"\t"<<ctime(&_expireOn);
	cout<<"\t"<<_description;
	cout<<endl;
}
/* Static Functions */
ShipInfo* ShipInfo::newEntry(unsigned long customerId){
	ShipInfo* temp=new ShipINfo();
	temp->_id=::newId();
	temp->_customerId=customerId;
	temp->_createdOn=time(NULL);
	strcpy(temp->_status,"New");
	if(FIle<ShipInfo>::find(ShIPINFO_FILE,temp->_id)!=NULL){
		cout<<"Internal error.Please retry.";
		system("cls");
		reutrn ShipInfo::newEntry(customerId);
	}
	cin.ignore();
	cout<<"\n\tItem DEscription: ";
	cin.getline(temp->_description,255);
	cout<<"\tItem weight: ";
	cin>>temp->_weight;
	cout<<"\tItem height: ";
	cin>>temp->_height;
	cout<<"\tItem depth: ";
	cin>>temp->_depth;
	cout<<"\tItem width: ";
	cin>>temp->_width;
	cin.ignore();
	cout<<"\tSource location: ";
	cin.getline(temp->_sourceLocation: ";
	cin.getline(temp->_destinationLocation,255);
	cout<<"\tInitial price: ";
	cin>>temp->_maxAmount;
	int iVal;
	cout<<"\texpire after(days): ";
	cin>>iVal;
	struct tm* t=localtime(&temp->_createdOn);
	t->tm_mday+=iVal;
	temp->_expireOn=mktime(t);
	cout<<"\tTime allocated(days): ";
	cin>>temp->_maxDaystoTransport;
		if(::canProceed()==1){
		File<ShipInfo>::insert(SHIPINFO_FILE,temp);
		return temp;
	}
	else{
		return NULL;
	}
}
void ShipInfo::displayColumns(){
	cout<<"Id";
	cout<<"\t"<<"\tStatus";
	cout<<"\t"<<"\tSource Location:";
	cout<<"\t"<<"\tDestination Location";
	cout<<"\t"<<"\tCreated On";
	cout<<"\t"<<"\tExpire On";
	cout<<"\t"<<"\tDescription";
	cout<<endl;
	cout<<"---------------------------------------------------------------------";
	cout<<endl;
}
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include"headers\Globals.h"
#include"headers\BidInfo.h"
#include"headers\ShipInfo.h"
#include"headers\File.h"
using namespace std;
Contact* shipper;
void shipperMenu(contact*item){
	shipper=item;
	int ch;
	unsigned long id;
	ShipInfo* itemShip=NULL;
	BidInfo* itemBid=NULL;
	File<ShipInfo>*fShip=NULL;
	File<BidInfo>* fBid=NULL;
	system("cls");
	do{
		cout<<"\n*****************************";
		cout<<"\nSHIPPER MENU: "<<shipper->getId();
		cout<<"\n*****************************";
		cout<<"\n1.Display available ship items.";
		cout<<"\n2.Display my bids";
		cout<<"\n3.Bid details";
		cout<<"\n4.New Bid";
		cout<<"\n58.clear screen";
		cout<<"\n9.Logoff";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch){
	case 1:
		ShipInfo::displayColumns();
		fShip=new File<ShipInfo>(SHIPINFO_FILE);
		while(!fShip->eof()){
			itemShip=fShip->read();
			if(itemShip!=NULL &&
				strcmp(itemShip->getStatus(),"Closed")!=0 &&
				itemShip->getWonByShipperId()==0){
					itemShip->displayAsRow();
				}
			delete(itemShip);
		}
		::pressKey();
		break;
	case 2:
		BidInfo::displayColumns();
		fBid=new File<BidInfo>(BIDINFO_FILE);
		while(!fBid->eof()){
			itemBid=fBid->read();
			if(itemBid!=NULL &&
				itemBid->getShipperId()==shipper->getId()){
					itemBid->displayAsRow();
				}
			delete(itemBid);
		}
		::pressKey();
		break;
	case 3:
		cout<<"enter Bid id: ";
		cin>>id;
		itemBid=FIle<BidInfo>::find(BIDINFO_FILE,id);
		if(itemBid==NULL){
			cout<<"no item Found!";
		}
			else{
				itemBid->displayDetails();
				delete(itemBid);
		}
		::pressKey();
		break;
	case 4:
		cout<<"enter ship id: ";
		cin>>id;
		itemShip=FIle<ShipInfo>::find(SHIPINFO_FILE,id);
		if(itemShip==NULL){
			cout<<"no item found!";
		}
		else{
			itemShip->displayDetails();
			if(::canProceed()==1){
				itemBid=BidInfo::newEntry(shipper->getId(),id);
				if(itemBid!=NULL){
					cout<<"Item successfully created with id: "<<itemBid->getId();
					delete(itemBid);
				}
			}
		}
		::pressKey();
		break;
	case 8:
		system("cls");
		break;
	case 9:
		system("cls");
		break;
				default:
				cout<<"\tError:101.Invalid option!";
				break;
			}
		}while(ch!=9);
	}


#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include"headers\Globals.h"
#include"headers\BidInfo.h"
#include"headers\ShipInfo.h"
#include"headers\File.h"
using namespace std;
Contact* customer;
  void customerMenu(Contact* item){
	customer=item;
	int ch;
	unsigned long id;
	ShipInfo* itemShip=NULL;
	BidInfo* itemBid=NULL;
	File<ShipInfo>* fShip=NULL;
	File<BidInfo>* fBid=NULL;
	system("cls");
	do{
	cout<<"\n***************************************************";
	cout<<"\nCUSTOMER MENU : FOR CUSTOMER Id "<<customer->getId();
	cout<<"\n***************************************************";
	cout<<"\n1.Input an item for shipping";
	cout<<"\n2.Remove an item from the list";
	cout<<"\n3.Display items whose bidding are not done yet";
	cout<<"\n4.Display the all ny items";
	cout<<"\n5.Accept Bid";
	cout<<"\n8.Clear screen";
	cout<<"\n9. Logoff";
	cout<<\nEnter your choice: ";
	cin>>ch;
	switch(ch){
		case 1:
			system("cls");
			cout<<"***********************************************";
			cout<<"\n\tNEW SHIP INFORMATION FORM";
			cout<<"\n*********************************************";
			itemShip=ShipInfo::newEntry(customer->getId());
			if(itemShip!=NULL){
				cout<<"\nShip Item successfully created with id"<<itemShip->getId();
				delete(itemShip);
			}
			::pressKey();
			break;

		case 2:
			cout<<"Enter Ship Item id: ";
			cin>>id;
			itemShip=File<ShipInfo>::find(SHIPINFO_FILE,id);
			if(itemShip==NULL){
			}
			else{
				itemShip->close();
				delete(itemShip);
			}
			::pressKey();
			break;
		case 3:
			ShipInfo::displayColumns();
			fShip=new File<ShipInfo>(SHIPINFO_FILE);
			while(!fShip->eof()){
				itemShip=fShip->read();
				if(itemShip!=NULL &&
					itemShip->getCustomerId()==customer->getId()){
					itemShip->displayAsRow();
				}
				delete(itemShip);
			}
			::pressKey();
			break;
		case 4:
			cout<<"Enter Ship Item Id: ";
			cin>>id;	
			BidInfo::displayColumns();
			fBid=new File<BidInfo>(BIDINFO_FILE);
			while(!fBid->eof()){
				itemBid=fBid->read();
				if(itemBid!=NULL &&
					itemBid->getShipItemId()==itemBid->getId()){
					itemBid->displayAsRow();
				}
				delete(itemBid);
			}
			::pressKey();
			break;
		case 5:
			cout<<"enter Bid Item Id: ";
			cin>>id;
			itemBid=File<BidInfo>::find(BIDINFO_FILE,id);
			if(itemBid==NULL){
				cout<<"no items found!!!";
			}
			else{
				itemBid->displayDetails();
				itemBid->accept();
				delete(itemBid);
			}
			::pressKey();
			break;
		case 8:
			system("cls")
			break;
		case 9:
			system('cls");
			break;
			default:
			cout<<"ERROR:303.Invalid input";
			break;
			}
		}while(ch!=9);
}	
				
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include"headers\Globals.h"
#include"headers\LogWriter.h"
#include"headers\Contact.h"
#include<windows.h>
using namespace std;
void mainMenu();
void contactRegistration(const char* contactType);
void contactLogin(const char* contactType);
void administrations();
void customerMenu(Contact*);
void shipperMenu(Contact*);
void mainMenu(){
	int ch;
	system("cls");
	do{
		cout<<"\n**************************************************";
		cout<<"\n\tMAIN MENU";
		cout<<"\n1.New Customer Registration";
		cout<<"\n2.Customer Login";
		cout<<"\n3.New Shipper Registration";
		cout<<"\n4.Shipper Login";
		cout<<"\n8.Clear screen";
		cout<<"\n9.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch){
	case 1:
		contactRegistration("Customer");
		break;
	case 2:
		contactLogin("Customer");
		break;
	case 3:
		contactRegistration("Shipper");
		break;
	case 4:
		contactLogin("Shipper");
		break;
	case 5: 
		administrations();
		break;
	case 8:
		system("cls");
		break;
	case 9: 
		cout<<"Press any key to exit";
		break;
		default:
		cout<<"ERROR:420...invalid";
		break;
		}
	}while(ch!=9);
}
void contactRegistration(const char* contactType){
	system("cls");
	cout<<"**********************************************************";
	if(strcmpi(contactType,"Customer")==0)
		cout<<"\nNEW CUSTOMER REGISTRATION FORM":
	else 
		cout<<"\nNEW SHIPPER REGISTRATION FORM":
	cout<<"\n************************************************************";
	Contact* temp=Contact::newEntry(contactType);
	if(temp!=NULL){
		cout<<"\nYour login id: "<<temp->getId();
		cout<<"\nPress any key to Continue...":
		getchar();
	}
}
void contactLogin(const char* contactType){
	char sval[20];
	unsigned long id;
	system("cls");
	cout<<"Enter your login Id: ";
	cin>>id;
	cin.ignore();
	cout<<"enter oyur password: ";
	cin>>id;
	cin.ignore();
	cout<<"enter your password:";
	strcpy(sval,readPassword());
	Contact* temp=Contact::validateLOgin(id,sval);
	if(temp!=NULL){
	getch();
	if(strcmpi(contactType,"Customer")==0)
		customerMenu(temp);
	else
		shipperMenu(temp);
	}
	else{
		cout<<"\nERROR........";
		::pressKey();
	}
}
void administrations(){
	system("cls");
}
int canProceed(){
	char ch;
	cout<<"\ndo you want to proceed?(y/n): ";
	cin>>ch;
	if(ch=='y'||ch=='Y')
		return 1;
	else
		return 0;
}
const char* readPassword(){
	string pass=="";
	char ch;
	ch=getch();
	while(ch!=13){
	pass.push_back(ch);
 	cout<<'*';
	ch=getch();
	}
	return pass.c_str();
}
int newId(){
	unsigned long uid=GetTickCount();
	::Sleep(10);
	int id=(int)uid;
	return id;
}
void pressKey(){
	cout<<"\nPress anyKey...";
	getch();
}
int main(){
	char input=0;
	system("cls");
	LogWriter::Enable();
	mainMenu()
	return 1;
}


#include<stdlib.h>
#include<iostream.h>
#include<string.h>

#include"headers\Globals.h"
#include"headers\Contact.h"
//#include"headers\ShipInfo.h"
#include"headers\File.h"
using namespace std;
/* int canProceed();
const char* readPassword();
int newId();*/
/* Non Static Functionc*/
Contact::Contact(){
	_id=0;
	strcpy(_name,"");
	strcpy(_address,"");
	strcpy(_type,"");
	strcpy(_password,"");
	_contactNo=_altContactNo=0;
}
unsigned long Contact::getId(){
	return_id;
}
void Contact::displayDetails(){
	cout<<"\n\tId: "<<_id;
	cout<<"\n\tName: "<<_name;
	cout<<"\n\tAddress: "<<_address;
	cout<<"\n\tContact No: "<<_contactNo;
	cout<<"\n\tAlt Contact No: "<<_altContactno;
	cout<<endl;
}
/* Static Functions*/
Contact* Contact::newEntry(const char* contactType){
Contact* temp=new Contact();
temp->_id=::newId();
strcpy(temp-._type,contactType);
if(File<Contact>::(CONTACT_FILE,temp->getId())!=NULL){
	cout<<"Internal error.retry";
	system("cls");
	reutrn Contact::newEntry(contactType);
}
cin.ignore();
cout<<"\n\tName: ";
cin.getline(temp->_name,100);
cout<<"\tAddress: ';
cingetline(temp->_address,500);
cout<<"\tContact No: ";
cin>>temp->_contactno;
cout<<"\tAlt Contactno: ";
cin>>temp->_altContactNo;	
