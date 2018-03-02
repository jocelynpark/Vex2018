#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in2,    gyro2,          sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           leftBack,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftMid,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           mobileLift,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           elevatorLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           swingArm,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           grabber,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightMid,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftFront,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Code for VEX 11040B
task main()
{
	short rightSpeed;
	short leftSpeed;
	short mobileSpeed;
	short armBaseSpeed;
	short elevatorLiftSpeed;
	short grabberSpeed;
	while (true)
	{		/*

		CHRIS'S CONTROLS

		*/
		//Controls Right Front Wheel
		if (vexRT[Ch2] > -35 && vexRT[Ch2] < 35)
		{
			rightSpeed = 0;
		}
		else
		{
			rightSpeed = vexRT[Ch2];
		}

		//Controls Left Front Wheel
		if (vexRT[Ch3] > -35 && vexRT[Ch3] < 35)
		{
			leftSpeed = 0;
		}
		else
		{
			leftSpeed = vexRT[Ch3];
		}

		//Controls Mobile Goal Lift
		if (vexRT[Btn5D]==1) {
			mobileSpeed = 127;
		}
		else if (vexRT[Btn5U]==1) {
			mobileSpeed = -127;
		}
		else {
			mobileSpeed = 0;
		}

		/*

		CAITLIN'S CONTROLS

		*/

		//Controls arm movement
		if (vexRT[Btn6DXmtr2]==1)
		{
			armBaseSpeed = 127;
		}
		else if (vexRT[Btn6UXmtr2]==1)
		{
			armBaseSpeed = -127;
		}
		else {
			armBaseSpeed = 0;
		}

		//Controls elevator lift movement
		if (vexRT[Btn5DXmtr2]==1)
		{
			elevatorLiftSpeed = 127;
		}
		else if (vexRT[Btn5UXmtr2]==1)
		{
			elevatorLiftSpeed = -127;
		}
		else {
			elevatorLiftSpeed = 0;
		}

		//Controls pinchers movement
		if (vexRT[Btn8UXmtr2]==1)
		{
			grabberSpeed = 127;
		}
		else if (vexRT[Btn8DXmtr2]==1)
		{
			grabberSpeed = -127;
		}
		else {
			grabberSpeed = 0;
		}

		motor[leftFront] = leftSpeed;
		motor[leftMid] = leftSpeed;
		motor[leftBack] = leftSpeed;
		motor[rightFront] = rightSpeed;
		motor[rightMid] = rightSpeed;
		motor[rightBack] = rightSpeed;
		motor[mobileLift] = mobileSpeed;

		motor[swingArm] = armBaseSpeed;
		motor[elevatorLift] = elevatorLiftSpeed;
		motor[grabber] = grabberSpeed;
	}
}
