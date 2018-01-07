#pragma config(Sensor, in1,    armLift,        sensorPotentiometer)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  lights,         sensorLEDtoVCC)
#pragma config(Motor,  port1,           rightFront,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port3,           rightMid,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightBack,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightBBack,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           liftArms,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftBBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftBack,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           leftMid,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftFront,     tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// RC CODE FOR THE NEW VEX ROBOT 11040A 8-MOTOR DRIVE


void leftDrive(short speed)
{
	motor[leftFront] = speed;
	motor[leftMid] = speed;
	motor[leftBack] = speed;
	motor[leftBBack] = speed;
}


void rightDrive(short speed)
{
	motor[rightFront] = speed;
	motor[rightMid] = speed;
	motor[rightBack] = speed;
	motor[rightBBack] = speed;
}

task main()
{
	short leftSpeed;
	short rightSpeed;

	SensorType[in2] = sensorNone;
	wait1Msec(1000);
	SensorType[in2] = sensorGyro;
	wait1Msec(2000);
	SensorValue[gyro] = 0; //positive counterclockwise

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	int mobileDist = 1800;

	////AUTONOMOUS////
	motor[liftArms] = -60;
	wait1Msec(900);
	motor[liftArms] = 0;
	while (SensorValue[rightEncoder] < mobileDist || SensorValue[leftEncoder] < mobileDist) {
		if (SensorValue[rightEncoder] > SensorValue[leftEncoder]) {
			leftDrive(127);
			rightDrive(0);
		}
		else if (SensorValue[rightEncoder] < SensorValue[leftEncoder]){
			leftDrive(127);
			rightDrive(127);
		}
	}
	motor[liftArms] = 60;
	wait1Msec(900);
	motor[liftArms] = 0;
	while (SensorValue[rightEncoder] < mobileDist || SensorValue[leftEncoder] < mobileDist) {
		if (SensorValue[rightEncoder] > SensorValue[leftEncoder]) {
			leftDrive(-127);
			rightDrive(0);
		}
		else if (SensorValue[rightEncoder] < SensorValue[leftEncoder]){
			leftDrive(-127);
			rightDrive(-127);
		}
	}

	while(true)
	{
		/*				!!!		DRIVE CONTROLS		!!!
		*/
		//To control the left side using channel 3
		if (vexRT[Ch3] > -35 && vexRT[Ch3] < 35)
		{
			leftSpeed = 0;
		}
		else
		{
			leftSpeed = vexRT[Ch3];
		}

		//To control the right side using channel 2
		if (vexRT[Ch2] > -35 && vexRT[Ch2] < 35)
		{
			rightSpeed = 0;
		}
		else
		{
			rightSpeed = vexRT[Ch2];
		}

		leftDrive(leftSpeed);
		rightDrive(rightSpeed);



		/*				!!!		MOBILE GOAL CARRIER CONTROLS		!!!

		Pressing Button 6U should bring the mobile goal carrier in
		Pressing Button 6D should bring the mobile goal carrier out

		When contracted, pot = 2102 - 2110
		When extended, pot = 464 - 465
		*/
		if(vexRT[Btn6U] == 1 /*&& SensorValue[armLift] <2110*/)
		{
			motor[liftArms] = 127;
		}
		else if(vexRT[Btn6D] == 1 /*&& SensorValue[armLift] > 465*/)
		{
			motor[liftArms] = -127;
		}
		else
		{
			motor[liftArms] = 0;
		}




		//light control (if getting one... VEX inverse the controls... idk y)
		//turning light on (0 = on)
		if (vexRT[Btn7R] == 1)
		{
			SensorValue[lights] = 0;
		}
		//turning light off (1 = off)
		else if (vexRT[Btn8L] == 1)
		{
			SensorValue[lights] = 1;
		}

	}
}
