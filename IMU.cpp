#include "IMU.hpp"

void IMU::setCalib(){
	readAll();
	antipitch=this->mesure[which+1];
	antiyaw=this->mesure[which+2];
	antiroll=this->mesure[which];
}

void IMU::noCalib(){
	readAll();
	antipitch=0;
	antiyaw=0;
	antiroll=0;
}


void IMU::readAll(){
	//On clear le buffer de mesure
	mesure.clear();
	int flag=0;
	int timer=0;
	std::string buffer;
	char next_byte='p';
	while(flag!=1)
	{
		//std::cout<<"Attente preparer "<<std::endl;
		//Attente du début du mot... on attend donc la fin du denrier mot
		// Tant qu'on ne reçoit pas un "\n" sur le port série,
		// on concatène le buffer
		while(next_byte!='\n'){
			arduino.get(next_byte);
			std::cout<<"Attente1 "<<next_byte<< " " << std::endl;
		}
		//arduino.get(next_byte);
		//std::cout<<"Attente2 "<<std::endl;
		int flag2=0;
		//Lecture	
		while(flag==0)
		{	//On lis les valeurs donnés par arduinoino
			
			arduino.get(next_byte);
			std::cout<<next_byte<< " Got it "<<std::endl;
			if(next_byte != ';' && next_byte != 'e') buffer = buffer+next_byte;
			else
			{
				// Quand on a reçu le \n de fin de ligne, on affiche le buffer
				// transformé en float (la tension) et on le vide
				 std::cout<<"BUffer "<<buffer<< " end"<<std::endl;
			   
			   	//Condition de fin
			   	if(next_byte=='e'){
			   		flag=1;
			   		std::cout<<"END OF ALL"<< std::endl;
			   	}
			   	//Nouvelle mesure entrée
			   	else{
			   		this->mesure.push_back(convertToDouble(buffer));
			   		std::cout<< buffer<< " at "<<flag2<<std::endl;
			   		buffer.clear();
			   		flag2++;
			   		
			   	}
			}
		}
		//Timer en cas de bug du programme
		timer++;
		//std::cout << timer << "Avant la fiiiin avec flag = " <<flag <<" et on lit " << next_byte<< std::endl;
		if(timer>500){
			printf("Closed\n");
			exit(0);

		}
		//Attention à la taille du vector
		while(this->mesure.size()<15){
			mesure.push_back(0);
		}
	}
}

void IMU::paint(Graph* g){
	g->draw(this);
}
