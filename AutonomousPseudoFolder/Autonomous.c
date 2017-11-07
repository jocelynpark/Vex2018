#pragma config(Motor,  port1,           backLeft,      tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           backRight,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           frontRight,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           LeftArm,       tmotorNone, openLoop)
#pragma config(Motor,  port6,           RightArm,      tmotorNone, openLoop)
#pragma config(Motor,  port7,           LeftArmPinch,  tmotorNone, openLoop)
#pragma config(Motor,  port8,           RightArmPinch, tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	const int SPEED = 120;
	const int TIME = 5; //in seconds
	while(autonomous) {
		
		void armForward(int speed) {
			motor[LeftArm] = speed;
			motor[RightArm] = speed;
		}
		
		void armBackward() {
			motor[LeftArm] = -127;
			motor[RightArm] = 127;
		}
		
		void pinchClose() {
			motor[LeftArmPinch] = 63;
			motor[RightArmPinch] = 63;
		}
		
		void pinchOpen() {
			motor[LeftArm] = -63;
			motor[RightArm] =-63;
		}
		
		void moveForward() {
			motor [leftArm] = 63;
			motor [RightArm] = 63;
		}
		
		void pinchClose(){
			motor [LeftArmPinch] = 63;
			motor [RightArmPinch] = 63;
	}
	motor[backLeft] = SPEED;
	motor[backRight] = SPEED;
	motor[frontLeft] = SPEED;
	motor[frontRight] = SPEED;
	wait1Msec(TIME * 1000);
	motor[backLeft] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	
	pinchOpen();
	wait1Msec(2000);
	armForward();
	pinchClose();
	armBackward();
	motor[backLeft] = -SPEED;
	motor[backRight] = -SPEED;
	motor[frontLeft] = -SPEED;
	motor[frontRight]= -SPEED;
	wait1Msec(TIME*1000);
	motor[backLeft] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	pinchopen();
  
	
}