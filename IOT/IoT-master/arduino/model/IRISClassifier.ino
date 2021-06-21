/*
ANNHub API for Arduino 
Date created: Fri, 15 Mar 2019
Author: Dr Tuan Nghia Nguyen
Copyright by ANS Center 2018
Website: https://www.anscenter.com

Usage:
1. Define an Neural Network object 
  ANN nnObj;
2. Perform prediction based on the neural network input
  For example, in XOR parity classification, there are two inputs and 1 output
  Truth table:
  0 XOR 0 --> 0
  0 XOR 1 --> 1
  1 XOR 0 --> 1
  1 XOR 1 --> 0
  
  //Define Input variable
  float Input[2];
  float Output[1];
  // Define Output variable
  Input[0]=1;
  Input[1]=0;
  // Perform prediction
  nnObj.Predict(Input,Output);
  // The output should be around 1
*/
#include "math.h"

void TanSig(float *iVal, float *oVal, uint8_t dim)
{
	for (uint8_t i = 0; i < dim; i++)
	{
		oVal[i] = 2 / (1 + exp(-2 * iVal[i])) - 1;
	}
}

void SoftMax(float *iVal, float *oVal, int dim)
{
	float softmaxWeight = 0;
	uint8_t i;
	for (i = 0; i<dim; i++){
			softmaxWeight = softmaxWeight + exp(iVal[i]);
	}
	for (i = 0; i<dim; i++){
			oVal[i] = exp(iVal[i]) / softmaxWeight;
	}
}
class ANN
{
	float nInput[4],nOutput[3];		

float IW[4][4] ={{0.23,1.29,-3.26,-3.04},{0.77,0.62,0.73,2.57},{0.07,-1.17,1.38,1.10},{0.20,1.19,-1.68,-1.57}};
float LW[3][4]={{1.94,-0.76,-2.70,4.33},{2.46,-1.11,1.06,-1.81},{-4.37,2.74,1.35,-2.73}};
float Ib[4] ={1.70,-1.64,0.39,-0.48};
float Lb[3] = {-0.25,0.69,-0.92};
float yminInput=-1.00;
float ymaxInput=1.00;
float xminInput[4]={4.30,2.00,1.00,0.10};
float xmaxInput[4]={7.90,4.40,6.90,2.40};

float yminOutput=0.00;
float ymaxOutput=1.00;
float xminOutput[3]={0.00,0.00,0.00};
float xmaxOutput[3]={1.00,1.00,1.00};

public:
	ANN(){ ;};
	~ANN(){;};
	uint8_t		Predict(float *ip,float *op);
	float  GetOutput(uint8_t indexVal){ return nOutput[indexVal]; }
};
uint8_t ANN::Predict(float *ip,float *op)
{
	uint8_t i, j;
	float a1[4];
	float n1[4];
	float n2[3];
  for (i = 0; i<4; i++) {
		nInput[i] = (ip[i] - xminInput[i])*(ymaxInput - yminInput) / (xmaxInput[i] - xminInput[i]) + yminInput;
	}
   for (i = 0; i<4; i++){
		n1[i] = 0;
		for (j = 0; j<4; j++) {
			n1[i] = n1[i] + IW[i][j] * nInput[j];
		}
		n1[i] = n1[i] + Ib[i];
	}
	TanSig(n1, a1, 4);

   for (i = 0; i<3; i++){
		n2[i] = 0;
		for (j = 0; j<4; j++) {
			n2[i] = n2[i] + LW[i][j] * a1[j];
		}
		n2[i] = n2[i] + Lb[i];
	}
	SoftMax(n2, nOutput, 3);
  for (i = 0; i<3; i++) {
		 nOutput[i] = (nOutput[i] - yminOutput)*(xmaxOutput[i] - xminOutput[i]) / (ymaxOutput - yminOutput) + xminOutput[i];
   op[i]=nOutput[i] ;
	}
return 0;
}
/*===================== YOUR PROGRAM STARTS FROM THIS LINE ==============================*/
/* Following Arduino codes demonstrate IRIS flower classification (https://en.wikipedia.org/wiki/Iris_flower_data_set).
 * Please modify these codes to suit your actual application. */

ANN myNeuralNetwork;
float Input[4];
float Output[3];
String inString[4] = {""};    
uint8_t myIndex=0;

//Example: Output= [1 0 0] --> ClassifiedLabel=1, Output=[0 1 0] -> --> ClassifiedLabel=2
uint8_t OutputMapping(float* op, float threshold){
  uint8_t sumOfOutput=0;
  uint8_t ClassifiedLabel;  // from 1 to n for class 1 to class n
  uint8_t mapOutput[3];
  for(uint8_t i=0;i<3;i++){
    if(op[i]<1-threshold){
      mapOutput[i]=0;
    }
    else {
      mapOutput[i]=1;
      ClassifiedLabel=i+1;
    }
    sumOfOutput =sumOfOutput+mapOutput[i];
  } 
  if(sumOfOutput==1){// Correct prediction
    return ClassifiedLabel;
  }
  else{ // Fail to give correct prediction
    return 0;       
  }
}
void DisplayInputOutput(float *ip,float *op){
         Serial.print("Inputs= [");
         for(uint8_t i=0;i<4;i++){
            Serial.print(ip[i]);  
            if(i==4-1){
              Serial.println(" ]");
            }
            else{
              Serial.print(" ;");
            }
         }
         Serial.print("Outputs= [");
          for(uint8_t i=0;i<3;i++){
            Serial.print(op[i]);  
            if(i==3-1){
              Serial.println(" ]");
            }
            else{
              Serial.print(" ;");
            }
         }  
}

// Please provide correct description depending on your application labels. This example demonstrates the IRIS flower classification.
void ExplainResult(float *op,float threshold){
         uint8_t label=OutputMapping(op,threshold);
         switch(label){
            case 1:  Serial.println(F("Prediction: This is Setosa flower."));break;              
            case 2:  Serial.println(F("Prediction: This is Versicolor flower."));break;
            case 3:  Serial.println(F("Prediction: This is Virginica flower.")); break;  
            default: Serial.println(F("Prediction: Failed to give prediction!!!"));break;    
         } 
         Serial.println(F("---------------------------------------------------------"));   
}

void setup() {  
  Serial.begin(115200);  // USB does not require BAUD
  while (!Serial)
  {
    delay(100);
  }
   Serial.println(F("Welcome to ANNHub API for Arduino by ANS Center (https://www.anscenter.com)."));
   Serial.println(F("Please enter inputs with comma seperation."));
   Serial.println(F("For example, four inputs in IRIS flower classification will have the format as  5.8,2.8,5.1,2.4."));;
   Serial.println(F("-----------------------------------------------------------------------------------------------"));
}

void loop() {
  while (Serial.available() > 0) {
      char inChar = (char)Serial.read();
        if(myIndex<4){
           inString[myIndex]+=(char)inChar;
        }
        if (inChar == ',')myIndex=myIndex+1;
      
      if (inChar == '\n') {
         myIndex =0;
         // You should modify this text to match your application
         Serial.println(F("IRIS flower classification")); 
         for(uint8_t i=0;i<4;i++){
            Input[i]=(float)inString[i].toFloat();
            inString[i] = "";
         }
         myNeuralNetwork.Predict(Input,Output);
         DisplayInputOutput(Input,Output);
         ExplainResult(Output,0.3); // Please change threshold to suit your need. Please also comment out this function if your application is regression type.
      }
    }
}