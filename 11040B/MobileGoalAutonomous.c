#pragma config(Sensor, in1,    liftAngle,      sensorPotentiometer)
#pragma config(Sensor, in2,    gyroScope,      sensorGyro)
#pragma config(Motor,  port1,           rightBack,     tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftBack,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           rightFront,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           leftFront,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           mobileLift,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftArmT,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           frontMotor,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           rightArmB,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           leftArmB,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          rightArmT,     tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void moveForward(int speed) {
		motor[leftFront] = speed;
		motor[leftBack] = speed;
		motor[rightFront] = speed;
		motor[rightBack] = speed;
}
void liftArm(int speed) {
		motor[leftArmT] = speed;
  	motor[rightArmT] = speed;
  	motor[leftArmB] = speed;
  	motor[rightArmT] = speed;
}
//Code for VEX 11040B
task main()
{
	int leftSpeed;
	int rightSpeed;
	int armBaseSpeed;
	int grabberSpeed;
	int mobileSpeed;

	SensorType[in2] = sensorNone;
 	wait1Msec(1000);
 	//Reconfigure Analog Port 2 as a Gyro sensor and allow time for ROBOTC to calibrate it
 	SensorType[in2] = sensorGyro;
 	wait1Msec(2000);
	/*
	//Close Pincher
	motor[frontMotor] = 127;
	wait1MSec(1000);
	//Lift Backward
	liftArm(80);
	wait1Msec(2000);
	liftArm(0);
	motor[frontMotor] = 0;
	*/

	//Move Forward a bit
	moveForward(-127);
	wait1Msec(700);
	moveForward(0);

	//Lift Backward
	liftArm(-80);
	wait1Msec(1400);
	liftArm(0);

	//Open Grabber
	motor[frontMotor] = -30;
	wait1Msec(1000);
	motor[frontMotor] = 0;

	//Move into Preload and Grab It
	moveForward(60);
	wait1Msec(700);
	moveForward(0);
	motor[frontMotor] = 30;

	//Lower Mobile Lift
	motor[mobileLift] = -127;
	wait1Msec(3500);
	motor[mobileLift] = 0;

	//Move towards Mobile Goal
	moveForward(-127);
	wait1Msec(1700);
	moveForward(0);

	//Put PreLoad on Mobile Lift
	liftArm(-80);
	wait1Msec(2000);
	liftArm(0);

	//Turns 180 degrees
	int degrees10 = 1800; //1 degree = 10, 180 degrees = 180

	while (abs(SensorValue[in2]) < degrees10)
	{
		motor[rightFront] = 127;
		motor[rightBack] = 127;
		motor[leftFront] = -127;
		motor[leftBack] = -127;
	}

	//Breif brake to stop some drift
		motor[rightFront] = 10;
		motor[rightBack] = 10;
		motor[leftFront] = -10;
		motor[leftBack] = -10;
		wait1Msec(1000);

	//Stops wheels
		motor[rightFront] = 0;
		motor[rightBack] = 0;
		motor[leftFront] = 0;
		motor[leftBack] = 0;
		wait1Msec(1200);
	/*
	//Open Pincher
	motor[frontMotor] = -127;
	wait1Msec(1500);
	motor[frontMotor] = 0;

	//Lift Arm Back
	liftArm(80);
	wait1Msec(2000);
	liftArm(0);

	//Close Pincher
	motor[frontMotor] = 127;
	wait1Msec(1500);
	motor[frontMotor] = 0;

	//Move Back to Zone
	moveForward(127);
	wait1Msec(1000);
	moveForward(0);

	//Turn to position in Zone
	motor[leftFront] = 127;
	motor[leftBack] = 127;
	wait1Msec(1500);
	motor[leftFront] = 0;
	motor[leftBack] = 0;

	//Lower Stacked Cone
	motor[mobileLift] = -80;
	wait1Msec(3000);
	motor[mobileLift] = 0;

	//Move Back
	moveForward(-127);
	wait1Msec(2000);
	moveForward(0);
	*/
}