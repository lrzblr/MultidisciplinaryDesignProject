const int enPin=8;
const int stepXPin = 2; //X.STEP
const int dirXPin = 5;  // X.DIR
const int stepYPin = 3; //Y.STEP
const int dirYPin = 6;  // Y.DIR
const int stepZPin = 4; //Z.STEP
const int dirZPin = 7;  // Z.DIR
#define X_LIMIT_PIN        9
#define Y_LIMIT_PIN        10
#define Z_LIMIT_PIN        11

////
int hiz=0;
int stepPin1=stepXPin;
int dirPin1=dirXPin;

int stepPin2=stepYPin;
int dirPin2=dirYPin;

int stepPin3=stepZPin;
int dirPin3=dirZPin;
////

const int stepsPerRev=45;
int pulseWidthMicros = 1000; 	// microseconds
int millisBtwnSteps = 1000;


void setup() {
 	Serial.begin(9600);
 	pinMode(enPin, OUTPUT);
 	digitalWrite(enPin, LOW);
 	pinMode(stepPin1, OUTPUT);
 	pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
 	pinMode(dirPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
 	pinMode(dirPin3, OUTPUT);
 	Serial.println(F("CNC Shield Initialized"));

  pinMode(X_LIMIT_PIN, INPUT_PULLUP);
  pinMode(Y_LIMIT_PIN, INPUT_PULLUP);
  pinMode(Z_LIMIT_PIN, INPUT_PULLUP);
  
}



void loop() {
 const  int objCount = 16; // Toplam obje sayısı
 const  int obj_x1[] = {0, 2, 9, 17, 9, 12, 17, 9, 12, 0, 2, 5, 2, 5, 0, 9}; // X1 değerleri  Sol alt köşe 
 const int obj_y1[] = {0, 0, 0, 0, 6, 6, 6, 11, 11, 12, 12, 12, 14, 14, 18, 18}; // Y1 değerleri  
 const int obj_x2[] = {2, 9, 17, 20, 12, 17, 20, 12, 17, 2, 5, 9, 5, 9, 9, 20}; // X2 değerleri  Sağ üst köşe
 const  int obj_y2[] = {12, 12, 6, 6, 11, 11, 18, 18, 18, 18, 14, 14, 18, 18, 20 ,20 }; // Y2 değerleri


  int homeX=digitalRead(X_LIMIT_PIN);
  while (homeX==1) { 
  digitalWrite(dirPin1, HIGH); //Changes the rotations direction
    for (int i = 0; i < 1; i++) {
 			digitalWrite(stepPin1, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin1, LOW);
 			delayMicroseconds(millisBtwnSteps);
      homeX=digitalRead(X_LIMIT_PIN);
 	  }
  }
 	delay(250); // One second delay
   /////////////////////////////////////////////////////////ZZZZZZ

 int homeZ=digitalRead(Z_LIMIT_PIN);
  while (homeZ==1) { 
  digitalWrite(dirPin3, LOW); //Changes the rotations direction
    for (int i = 0; i < 1; i++) {
 			digitalWrite(stepPin3, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin3, LOW);
 			delayMicroseconds(millisBtwnSteps);
      homeZ=digitalRead(Z_LIMIT_PIN);
 	  }
  }
 	delay(250); // One second delay
  digitalWrite(dirPin3, HIGH); //Changes the rotations direction
   for (int i = 0; i < 820; i++) {                                     ///////////////////// KALEMİN KONUMUNA GÖRE Z DEĞİŞİYO ONU BURDAN AYARLIYOZ
 			digitalWrite(stepPin3, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin3, LOW);
 			delayMicroseconds(millisBtwnSteps);
      }



   ///////////////////////////////////////////////////////////ZZZZ
  digitalWrite(dirPin1, LOW); //Changes the rotations direction
   for (int i = 0; i < 250; i++) {
 			digitalWrite(stepPin1, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin1, LOW);
 			delayMicroseconds(millisBtwnSteps);
      }
    




 ////////////////////////////////////////////////
  int homeY=digitalRead(Y_LIMIT_PIN);
  while (homeY==1) { 
  digitalWrite(dirPin2, HIGH); //Changes the rotations direction
    for (int i = 0; i < 1; i++) {
 			digitalWrite(stepPin2, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin2, LOW);
 			delayMicroseconds(millisBtwnSteps);
      homeY=digitalRead(Y_LIMIT_PIN);
 	  }
  }
 	delay(250); // One second delay
  digitalWrite(dirPin2, LOW); //Changes the rotations direction
   for (int i = 0; i < 50; i++) {
 			digitalWrite(stepPin2, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin2, LOW);
 			delayMicroseconds(millisBtwnSteps);
      }




    /////////////////////////////////////////////////////////////////////////  ÇİZİM BURADA BAŞLIYOR
  for (int i = 0; i < objCount; ++i) {
    
    digitalWrite(dirPin3, LOW); //Changes the rotations direction
    for (int i = 0; i < 200; i++) {
 			digitalWrite(stepPin3, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin3, LOW);
 			delayMicroseconds(millisBtwnSteps);
 	}
 	delay(hiz); // One second delay

    if (i == 0) {
      	moveObject(obj_x1[i], obj_y1[i], obj_x2[i], obj_y2[i]); //İLK NOKTA İÇİN İSTİSNA
    } else {
		digitalWrite(dirPin3, HIGH); //Changes the rotations direction
		for (int i = 0; i < 200; i++) {
				digitalWrite(stepPin3, HIGH);
				delayMicroseconds(pulseWidthMicros);
				digitalWrite(stepPin3, LOW);
				delayMicroseconds(millisBtwnSteps);
		}

		move(obj_x1[i-1] , obj_y1[i-1] , obj_x1[i], obj_y1[i]);

		
		digitalWrite(dirPin3, LOW); //Changes the rotations direction
		for (int i = 0; i < 200; i++) {
				digitalWrite(stepPin3, HIGH);
				delayMicroseconds(pulseWidthMicros);
				digitalWrite(stepPin3, LOW);
				delayMicroseconds(millisBtwnSteps);
		}
		delay(hiz);


      	moveObject(obj_x1[i], obj_y1[i], obj_x2[i], obj_y2[i]); //ESKİ KONUMDAN YENİDEN ROTA HESAPLA
    }
    
    digitalWrite(dirPin3, HIGH); //Changes the rotations direction
    for (int i = 0; i < 200; i++) {
 			digitalWrite(stepPin3, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin3, LOW);
 			delayMicroseconds(millisBtwnSteps);
 	  }
    
    
  }
  delay(50000);
}



/*void loop() {
 	Serial.println(F("Running clockwise"));
 	digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
 	// Makes 200 pulses for making one full cycle rotation
 	for (int i = 0; i < stepsPerRev; i++) {
 			digitalWrite(stepPin, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin, LOW);
 			delayMicroseconds(millisBtwnSteps);
 	}
 	delay(1000); // One second delay

 	Serial.println(F("Running counter-clockwise"));
 	digitalWrite(dirPin, LOW); //Changes the rotations direction
 	// Makes 400 pulses for making two full cycle rotation
 	for (int i = 0; i < stepsPerRev; i++) {
 			digitalWrite(stepPin, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin, LOW);
 			delayMicroseconds(millisBtwnSteps);
 	}
 	delay(1000);
}*/
/////


void move(int x1, int y1, int x2, int y2){
	int deltaX = x2 - x1;
  	int deltaY = y2 - y1;

	if(deltaX <0){
		deltaX=-deltaX;
		for (int i = 0; i < deltaX; i++) {
    
    		digitalWrite(dirPin1, HIGH); //Changes the rotations direction
			for (int j = 0; j < stepsPerRev; j++) {
					digitalWrite(stepPin1, HIGH);
					delayMicroseconds(pulseWidthMicros);
					digitalWrite(stepPin1, LOW);
					delayMicroseconds(millisBtwnSteps);
			}
 		delay(hiz); // One second delay
 		}
		
	}else{
		for (int i = 0; i < deltaX; i++) {
    
    		digitalWrite(dirPin1, LOW); //Changes the rotations direction
			for (int j = 0; j < stepsPerRev; j++) {
					digitalWrite(stepPin1, HIGH);
					delayMicroseconds(pulseWidthMicros);
					digitalWrite(stepPin1, LOW);
					delayMicroseconds(millisBtwnSteps);
			}
 		delay(hiz); // One second delay
 		}
	}

	///////////////////////YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY//////////////////////////////////

	if(deltaY <0){
		deltaY=-deltaY;
		for (int i = 0; i < deltaY; i++) {
    
    		digitalWrite(dirPin2, HIGH); //Changes the rotations direction
			for (int j = 0; j < stepsPerRev; j++) {
					digitalWrite(stepPin2, HIGH);
					delayMicroseconds(pulseWidthMicros);
					digitalWrite(stepPin2, LOW);
					delayMicroseconds(millisBtwnSteps);
			}
 		delay(hiz); // One second delay
 		}
		
	}else{
		for (int i = 0; i < deltaY; i++) {
    
    		digitalWrite(dirPin2, LOW); //Changes the rotations direction
			for (int j = 0; j < stepsPerRev; j++) {
					digitalWrite(stepPin2, HIGH);
					delayMicroseconds(pulseWidthMicros);
					digitalWrite(stepPin2, LOW);
					delayMicroseconds(millisBtwnSteps);
			}
 		delay(hiz); // One second delay
 		}
	}



}


void moveObject(int x1, int y1, int x2, int y2) {
  int deltaX = x2 - x1;
  int deltaY = y2 - y1;

  for (int i = 0; i < deltaX; i++) {
    
    digitalWrite(dirPin1, LOW); //Changes the rotations direction
    for (int j = 0; j < stepsPerRev; j++) {
 			digitalWrite(stepPin1, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin1, LOW);
 			delayMicroseconds(millisBtwnSteps);
 	}
 	delay(hiz); // One second delay
  }

  for (int i = 0; i < deltaY; i++) {
    
    digitalWrite(dirPin2, LOW); //Changes the rotations direction
    for (int j = 0; j < stepsPerRev; j++) {
 			digitalWrite(stepPin2, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin2, LOW);
 			delayMicroseconds(millisBtwnSteps);
 	}
 	delay(hiz); // One second delay
  }

  for (int i = 0; i < deltaX; i++) {
    
    digitalWrite(dirPin1, HIGH); //Changes the rotations direction
    for (int j = 0; j < stepsPerRev; j++) {
 			digitalWrite(stepPin1, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin1, LOW);
 			delayMicroseconds(millisBtwnSteps);
 	}
 	delay(hiz); // One second delay
  }

  for (int i = 0; i < deltaY; i++) {
  
    digitalWrite(dirPin2, HIGH); //Changes the rotations direction
    for (int j = 0; j < stepsPerRev; j++) {
 			digitalWrite(stepPin2, HIGH);
 			delayMicroseconds(pulseWidthMicros);
 			digitalWrite(stepPin2, LOW);
 			delayMicroseconds(millisBtwnSteps);
 	}
 	delay(hiz); // One second delay
  }
}