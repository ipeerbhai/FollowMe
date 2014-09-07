// Shazbot is the alias.  Project 1 is the Robotics 101 robot.
// BOM:
//	2 nema-17 steppers
//	BeagleBone Black.
//	USB Camera.
//	2 stepper drivers
//	1 battery
//	1 breadboard.
//	loads o' jumpers
//	1x Chassis.( What this drawing is for... ) 
//		main lasercut baord.
//			slots for zip-ties.
//		Nema motor mounts. ( m3x16 screws assumed )
//		wheels.
use <../Common_Drawings/External/ExternalDrawings.scad>;
//include <../Common_Drawings/ImranDesigned/ScrewsNutsWashers.scad>;
use <../Common_Drawings/ImranDesigned/Electrical.scad>;
use <../Common_Drawings/ImranDesigned/Bearings.scad>;
use <../Common_Drawings/ImranDesigned/MiscParts.scad>;

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

// For my MakerBot. Set as appropriate for other production processes.
g_nHoleErrorXY = 0.40; // This is to handle the hole error due to whatever process I'm using ( printing, etc... )
g_nHoleErrorXZ = 0.40; // This is to handle the hole error due to whatever process I'm using ( printing, etc... )
g_nPostError = .19; // Turns out posts have different error than holes.
g_nPostEccentricityError = 0.45; // This is the "elipse" error diameter between major/minor axis in posts.
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
// Module Area
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------
//	pre-manufactured parts
//------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is the Camera.  Logitech C910 is what I used ( but cheaper/better abound. )
module Camera()
{
	// 2 parts
	// The view part is 105 x 35 x 40
	// Base = 45 x 45 x 10
	// Camera is 35mm above the base
	color("grey")
	{
		translate( [0, 45/2 + 35/2, 35] )
			FilletedCube( 105, 35, 40, 3 );
		
		translate( [0, 10, 20] )
			rotate( [-45, 0, 0] )
				cube( size = [ 20, 20, 40 ], center = true );
			
			RoundedCube(45, 45, 10, 3);
	}
	
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is the TI Stellaris
module Stellaris()
{
	// 60 x 80 x 25
	color("red")
		cube( size = [60, 80, 25], center = true );
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a cube that represents the BreadBoard
module BreadBoard()
{
	// 175 x 75 x 15
	color("white")
		cube( size = [175, 75, 15], center = true );
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	The battery
module Battery()
{
	// 40 x 120 x 25
	color( "orange" )
		FilletedCube( 40, 120, 25, 3 );
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	The BeagleBone Black.
module BBB()
{
	// 60 x 90 x 25
	color("Black")
		RoundedCube( 60, 90, 25, 4 );
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a caster wheel, Amazon ASIN = B004FRRLLU
module CasterWheel()
{
	color("grey")
	{
		union()
		{
			rotate( [90, 0, 0] )
				cylinder( h = 55, r = 55/2, $fn = 100, center = true );
			translate([ -55/2, 0, 55/2])
				cylinder( h = 38, r = 38/2, $fn = 100, center = true );
			translate([ -55/2, 0, 55/2 + 38/2 + 11/2 - 0.01])
				cylinder( h = 26, r = 11/2, $fn = 100, center = true ); // This is the top cylinder( the mounting post )
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------
//	This is a toshiba encore tablet
module ToshTab()
{
	cube( size = [135.92, 10.65, 213.36], center = true );
}

//------------------------------------------------------------------------------------------------------------------------------
//	Helper parts( not parts on their own -- but sub-assemblies
//------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a helper module -- it removes a horizontal slot for a zip-tie from a board.  Meant for laser-cutting or milling.
module SlotSlug( nHeight = 300, nLength = 10, nRadius = 5 )
{
	nOffset = nLength/2 - 1;
	color("green")
	{
		hull()
		{
			for ( x = [-nOffset, nOffset] )
				translate( [ x, 0, 0 ] )
					cylinder( h = nHeight, r = nRadius, $fn = 100, center = true );
			
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a "slug"( like a bullet that removes things ) and it removes the motor mounting holes.
module MotorMountSlug(nMainDiameter = 4.3)
{
	// Remove some 5mm screw holes.  They can go through.
	for ( y = [-22, 22] )
		translate( [0, y, 0] )
			cylinder( h = 100, r = (nMainDiameter + g_nHoleErrorXY)/2, $fn = 100, center = true );
	translate( [-35, 0, 0] )
		cylinder( h = 100, r = (nMainDiameter + g_nHoleErrorXY)/2, $fn = 100, center = true );
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a slug common to both the motivator plate and the brain plate.
module commonPlateSlug()
{
	// Bolts, M5, 8 or 12 mm long.
	for ( i = [ 
				[-27, 85.5, -8 ], 
				[27, 85.5, -8],
				[-70, 45, -8 ], 
				[70, 45, -8],
				[-95, -10, -3],
				[-95, -40, -3],
				[95, -10, -3],
				[95, -40, -3],
				[-27, -95, -8 ], 
				[27, -95, -8],
				
				
		] )
		translate( i )
			cylinder(h = 100, r = 4.5/2, $fn = 100, center = true);

	// This is to round out the "motivator" board into a surfboard...
	translate( [0, 2, 0] )
		difference()
		{
			cylinder( h = 100, r = 400, $fn = 100, center = true );
			cylinder( h = 101, r = 205/2, $fn = 100, center = true );
			translate( [0, -220/2, 0] )
				cube( size = [206, 221, 110], center = true );
		}

	// Add in the hole for the caster wheel mount.
	translate( [0, 85.5, 0] )
		cylinder( h = 110, r = 11/2, $fn = 100, center = true );

}
//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a "slug" that removes the zip-tie and screw holes in the motivator plate.
module MotivatorSlug()
{
	commonPlateSlug();
	nDistanceToMotor = 95;
	nDistanceToMotorMount = -40 - 42;

	translate( [nDistanceToMotor, nDistanceToMotorMount, 0] )
		rotate( [0, 0, 0] )
			MotorMountSlug();
	translate( [-nDistanceToMotor, nDistanceToMotorMount, 0] )
		rotate( [0, 0, 180] )
			MotorMountSlug();
	
	// Let's start putting slots everyplace ( for zip ties ).
	for ( i = [
				[55, 75, 0],
				[-55, 75, 0],
				[55, 15, 0],
				[85, 15, 0],
				[00, 15, 0],
				[-55, 15, 0],
				[00, 15, 0],
				[-85, 15, 0],
				[00, -75, 0],
				[85, -75, 0],
				[00, -75, 0],
				[-85, -75, 0]
		] )
	{
		translate(i)
			SlotSlug(11, 10, 3);
	}

	// Wiring holes
	for ( i = [
				[45, -90, 0],
				[-45, -90, 0]
		] )
	{
		translate(i)
			rotate( [0, 0, 90] )
				SlotSlug(11, 15, 5);
		
	}	
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is the hole pattern for the upper board.
module brainSlug()
{
	commonPlateSlug();
	
	// The slots for zip ties
	for ( i = [
				[55, 75, 0],
				[-75, -80, 0],
				[-25, -80, 0],
				[75, -85, 0],
				[25, -85, 0],
				[-75, 10, 0],
				[-25, 10, 0],
				[75, 17, 0],
				[25, 17, 0],
				[0, 17, 0],
				[-35, 35, 0],
				[35, 35, 0],
				[-35, 65, 0],
				[35, 65, 0]
		] )
	{
		translate(i)
			SlotSlug(11, 10, 3);
	}
	for ( i = [
				[30, 50, 0],
				[-30, 50, 0],
				[-12, -60, 0],
				[-12, -30, 0],
				[-12, 0, 0],
				[12, -60, 0],
				[12, -30, 0],
				[12, 0, 0],
				[-85, -60, 0],
				[-85, -30, 0],
				[-85, 0, 0],
				[85, -60, 0],
				[85, -30, 0],
				[85, 0, 0],
				
		] )
	{
		translate(i)
			rotate( [0, 0, 90] )
				SlotSlug(110, 10, 3);
	}
	
	// wire path
	for ( i = [
				[0, -45, 0],
				[45, -90, 0],
				[-45, -90, 0]
		] )
	{
		translate(i)
			rotate( [0, 0, 90] )
				SlotSlug(11, 15, 5);
		
	}	
	
	
}

//------------------------------------------------------------------------------------------------------------------------------
//	Printed parts( to be 3d printed )
//------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	experimental tablet slug
module TabletSlug( nWidth = 135.92, nThickness = 10.65 )
{
	hull()
	{
		for ( x = [-nWidth/2, nWidth/2] )
			translate( [x, 0, 0] )
				cylinder( h = 55, r = nThickness/2, $fn = 100, center = true );
	}
}
//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	Experimental tablet holder
module TabletHolder( nWidth = 137.16, nThickness = 10.922 )
{
	difference()
	{
		RoundedCube( nWidth + 25, nThickness*2, 52, 3);
		TabletSlug();
		translate( [0, -25/2, 10] )
			cube( size = [125, 25, 55], center = true );
		// Hollow out the backing
		for (z = [-40/2: 7: 50/2] )
			for (x = [-138/2 : 7 : 138/2] )
				translate( [x, 8, z] )
					rotate( [90, 15, 0] )
						cylinder( h = 15, r = 3, $fn = 6, center = true );
	}
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is an experiment for a cheaper to make  nema-17 motor mount.
module experimentalMotorMount(nHeight = 52, nWallthickness = 3)
{
	nSupportHeight = 52 /9;
	difference()
	{
		experimentalSpacer( 44, nHeight );
		translate( [0, 20, -nHeight/2  + 42/2] )
			rotate( [-90, 0, 0] )
				Nema17Slug();
		translate( [0, -42/2 + 2.45, -nHeight/2  + 42/2] )
			cube( size = [49, 42, 43], center = true );
	}
	// Add a cross-brace.
	translate([ 0, -35/2 + 3.5, nHeight/2 - nSupportHeight/2])
		cube( size = [nWallthickness * 2, 35, nSupportHeight], center = true );
	// Final screw support...
	translate( [0, -35, nHeight/2 - nSupportHeight/2 ] )
		difference()
		{
			cylinder( h = nSupportHeight, r = 5.5, $fn = 100, center = true );
			cylinder( h =  nSupportHeight + 0.1, r = ( 4.5 + g_nHoleErrorXZ )/2, $fn = 100, center = true );
		}
	
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a nema-17 motor mount.
module MotorMount( bWithMotor = 0)
{
	difference()
	{
		union()
		{
			FilletedCube(16, 55, 45, 3); // The main part of the mount.
			translate( [0 -40/2, 0, -45/2 + 4/2] )
				RoundedCube( 40, 30, 4, 3);
		}
		// Remove the motor
		translate( [12, 0, 0] )
			rotate( [0, 90, 0] )
				mirror( [1, 0, 0] )
					Nema17Slug();
		// The holes to mount the motor to a board.
		MotorMountSlug();
	}
	
	if ( bWithMotor == 1 )
	{
		translate( [-18, 0, 0] )
			rotate( [0, 90, 0])
				Nema17();

	}
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a support for the motor mount -- to attach to the motivator plate.
module motorMountSupport( nHeight = 27 )
{
	// This is 3 cylinder supports for the screws with 2 cross-beams.
	// cylinder 1
	cube( size = [3, 35, nHeight], center = true ); 
	translate( [32/2, 0, 0] )
		cube( size = [30, 3, nHeight], center = true ); 
	
	for( i = [
			[0, -22, 0],
			[0, 22, 0],
			[35, 0, 0],
		] )
		translate(i)
			difference()
			{
				cylinder( h = nHeight, r = 5.5, $fn = 100, center = true );
				cylinder( h = nHeight* 10 + 1, r = ( 5 - 0.46 + g_nHoleErrorXY)/2, $fn = 100, center = true );
			}
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a wheel attached to the motor( aka a driven wheel ).
module Wheel( nDiameter = 65 )
{
	nLeadScrewSize = 15.90;
	nCouplerLength = 23;
	nSetScrewMotorSize = 2.7051;
		difference()
		{
			union()
			{
				cylinder( h = 10, r = ( nDiameter + g_nHoleErrorXY )/2, $fn = 100, center = true );
				translate( [0, 0, -10/2 + nCouplerLength/2] )
					cylinder( h = nCouplerLength, r = ( 26 + g_nHoleErrorXY )/2, $fn = 100, center = true );
			}
			translate( [0, 0, nCouplerLength/2 - 10/2] )
				FlangedRod( 4.95, g_nHoleErrorXY, nCouplerLength + 0.1 );
			for ( theta = [ 0, 90 ] )
			{
				translate( [nLeadScrewSize/2 * cos( theta) - 1, nLeadScrewSize/2 * sin( theta) - 1, 0] )
					rotate( [0, 90, theta] )
					{
						// Z position determines which screw size to use -- motor or lead.
						for( z = [-nCouplerLength/2 ] )
							translate( [z, 0, 0] )
								cylinder( h = nLeadScrewSize, r = (nSetScrewMotorSize + g_nHoleErrorXZ)/2, $fn = 100, center = true );
					} // End rotate
			} // End For
		}
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a spacer for the left/right between the two plates.
module plateSpacer(nHeight = 50 )
{
	rotate( [0, 0, 90] )
		experimentalSpacer( 30, nHeight );
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a support for the rear between the two plates.
module rearSupport(nHeight = 50)
{
	experimentalSpacer( 54, nHeight );
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	The support up front for the caster wheel
module frontSupport(nHeight = 50 )
{

	translate( [0, -10, 0] )
		cylinder( h = 100, r = 17/2, $fn = 100, center = true );
	difference()
	{
		RoundedCube( 70, 40, nHeight);
		for ( x = [-27, 27] )
			translate( [x, -10, 0] )
				cylinder( h = 200, r = ( 5 - 0.46 + g_nHoleErrorXY ) /2, $fn = 100, center = true );
		translate( [0, -10, 0] )
		{
			cylinder( h = 200, r = ( 10.85 + g_nHoleErrorXY )/2, $fn = 100, center = true );
			translate( [0, 0, -nHeight/2 + 19/2] )
				experimentalCasterSlug();
		}
		translate( [0, -95, 0] )
			commonPlateSlug();
	}
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a slug to remove for the center wheel.
module experimentalCasterSlug(nDiameter = 10.85, nBaseHeight = 13, nTopHeight = 6 )
{
	nOffset = (nBaseHeight - nTopHeight)/2;
	translate( [0, 0, nOffset] )
	{
		translate( [0, 0, -nBaseHeight/2 ] )
			FlangedRod( nDiameter, g_nHoleErrorXY, nBaseHeight );
		translate( [0, 0, nTopHeight/2 ] )
			FlangedRod( nDiameter, g_nHoleErrorXY, nTopHeight );
	}
	translate( [0, 0, (nBaseHeight + nTopHeight)/2] )
		sphere( r = (nDiameter + 2.4)/2, $fn = 100, center = true );
	for ( x = [-27, 27] )
	translate( [x, 0, 0] )
		{
			cylinder( h = nBaseHeight + nTopHeight, r = ( 5 - 0.46 + g_nHoleErrorXY ) /2, $fn = 100, center = true );
			translate( [0, 0, (nBaseHeight + nTopHeight)/2] )
				sphere( r = ( 5 - 0.46 + g_nHoleErrorXY )/2, $fn = 100, center = true );
		}

}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a small mount for the center wheel.
module experimentalCasterMount(nBaseHeight = 11, nTopHeight = 6)
{
	difference()
	{
		translate( [5, 0, 0] )
			cube( size = [5, 15, nBaseHeight + nTopHeight], center = true );
		//cylinder( h = 5, r = 18/2, $fn = 100, center = true );
		experimentalCasterSlug( 10.85, nBaseHeight, nTopHeight );
	}
	experimentalCasterSlug();
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a mount for the caster wheel that can be integrated with the tablet holder.
module tabletCasterMount( mountHeight = 19 )
{
	difference()
	{
		union()
		{
			cylinder( h = mountHeight, r = 10, $fn = 100, center = true );
			translate( [0, 0, mountHeight/2] )
				sphere( r = 10, $fn = 100, center = true );
			for ( x = [-27, 27] )
				translate( [ x, 0, 0] )
					{
						cylinder( h = mountHeight - 0.1, r = 7/2, $fn = 100, center = true );
						translate( [0, 0, mountHeight/2] )
							sphere( r = 7/2, $fn = 100, center = true );
					}
			//cube( size = [  27*2, 3, mountHeight - 0.1 ], center = true );
			for ( x = [1, -1] )
				translate( [27 *x, 0, 0] )
					rotate( [0, 0, -17.8 * x] )
					{
						cube( size = [  27*2, 3, mountHeight - 0.1 ], center = true );
						translate( [27 * x, 0, 0] )
							cylinder( h = mountHeight - 0.1, r = 7/2, $fn = 100, center = true );
					}
		}
		experimentalCasterSlug();
	}
}
//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	This is a general purpose spacer.  acts as M5 nut.
module experimentalSpacer( nScrewHoleDistance = 25, nHeight = 50, nWallThickness = 3)
{
	nDiameter = 5 - 0.5;
	nOuterShellRadius = ( 5 + nWallThickness*2 )/2; // How thick is the final cylinder
	difference()
	{
		union()
		{
			for ( x = [-nScrewHoleDistance/2, nScrewHoleDistance/2] )
				translate( [x, 0, 0] )
						cylinder( h = nHeight, r = nOuterShellRadius, $fn = 100, center = true );
			translate( [0, nOuterShellRadius - nWallThickness/2, 0 ] )
				cube( size = [nScrewHoleDistance, nWallThickness, nHeight], center = true );
		}
	for ( x = [-nScrewHoleDistance/2, nScrewHoleDistance/2] )
		translate( [x, 0, 0] )
			FlangedRod( nDiameter, g_nHoleErrorXY, nHeight );
	}
}
//------------------------------------------------------------------------------------------------------------------------------
//	Cut parts( to be laser-cut or milled out )
//------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	the brain plate houses the computers and sensor subsystems  It's the "Head" of the robot.
module BrainPlate( nWidth = 205, nLength = 220)
{
	difference()
	{
		RoundedCube( nWidth, nLength, 3, 6);
		brainSlug();
	}
}

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	the motivation plate houses the power and motion subsystems, and mounts the sensors/brains  It's the "feet" of the robot.
module MotivationPlate( nWidth = 205, nLength = 220)
{
	difference()
	{
		RoundedCube( nWidth, nLength, 3, 4);
		MotivatorSlug();
	}
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
// Main Area
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------
// Module:
//	Layout takes all the pre-manufactured parts and "floats" them in space where they need to be to have a working contraption.
//	I can then use it to design and align all other parts.
module Layout()
{
	nDistanceToMotor = 95;
	nDistanceToMotorMount = -40;
	
	//---
	// Create a construction plane above the main board for the battery, breadboard, and maybe camera
	translate( [0, -30, 10] )
	{
		// the central seed is probably the breadboard, or maybe the battery.
		BreadBoard();
		translate( [0, 75, 3] )
			rotate( [0, 0, 90] )
				Battery();
	}
	//---
	// A construction plane for the BBB, TI Stellaris, and maybe camera
	translate( [0, -35, 60] )
	{
		translate( [50, 0, 0] )
			rotate( [0, 0, 0] )
				BBB();
		translate( [-50, 0, 0] )
			rotate( [0, 0, 0] )
				Stellaris();
		translate( [0, 80, -5 ] )
			Camera();
	}
	
	//---
	// A different construction plane for things below the main baord.
	translate( [0, -42, -28] ) // use ( [0, -42, -28] ) for final position.
	{
	
		translate( [nDistanceToMotor, nDistanceToMotorMount, -45/2] )
			rotate( [180, 0, 0] )
			{
				MotorMount(1);
				translate( [15, 0, 0] )
					rotate( [0, -90, 0] )
						Wheel();
			}

		// Another rotation.
		translate( [-nDistanceToMotor, nDistanceToMotorMount, -45/2] )
			rotate( [180, 0, 0] )
				rotate( [0, 0, 180] )
				{
					MotorMount(1);
					translate( [15, 0, 0] )
						rotate( [0, -90, 0] )
							Wheel();
				}
		// Caster wheel
		translate( [0, 100, -22.5] ) // use [95, -22.5, -22.5] to overlay a powered wheel.
			rotate( [0, 0, -90] )
				CasterWheel();
	}
	// construction place for spacers between the two plates.
	translate([0, 0, 25])
	{
		for ( x = [-96, 96] )
		translate( [x, -25, 0] )
			plateSpacer();
		translate( [0, -95, 0] )
			rearSupport();
		translate( [0, 95, 0] )
			frontSupport();
	}
	
	// construction plane for the motor mount supports.
	translate( [0, 0, -30/2] )
	{
		translate( [-95, -82.5, 0] )
			motorMountSupport();
		translate( [95, -82.5, 0] )
			rotate( [0, 0, 180] )
				motorMountSupport();
	}

}

//------------------------------------------------------------------------------------------------------------------------------
module m3Washer(nHeight = 3 )
{
	difference()
	{
		cylinder( h = nHeight, r = 4.5, $fn = 100, center = true );
		cylinder( h = nHeight + 0.1, r = (3.5 + g_nHoleErrorXY)/2, $fn = 100, center = true );

	}
}
//------------------------------------------------------------------------------------------------------------------------------
//
module BBBVersion()
{
	
	translate( [0, 0, 50] )
		BrainPlate();
	MotivationPlate();	
}
//------------------------------------------------------------------------------------------------------------------------------
module ToshibaTabletVersion()
{
//	%color("black")
//		translate( [0, 25, 225/2] )
//			ToshTab();
	difference()
	{
		union()
		{
			TabletHolder();
			translate( [0, 35, -33/2] )
				tabletCasterMount();
			for ( x = [-1, 1] )
				translate( [x * 66, 18, -33/2] )
					rotate( [0, 0, x * 55] )
						cube ( size = [3, 30, 19], center = true );
		}
		for ( x = [-1, 1] )
			translate( [76 * x, 6, -33.1/2] )
				cylinder( h = 19, r = 5/2, $fn = 100, center = true );
	}
}

//m3Washer();
//main();
//Layout();
// Manufacture area!

//rotate( [-90, 0, 0] )
//	experimentalMotorMount();
//commonPlateSlug();
//translate( [0, 45, 0] )
//	TabletHolder();
ToshibaTabletVersion();
//experimentalCasterSlug();
//plateSpacer();
//rearSupport();
//Wheel();
