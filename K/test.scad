// Parametric letter module
// David Eccles (gringer) <bioinformatics@gringene.org>

$fn=30;

//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//12345678901234567890123456


// letter widths
lwds = [4,
        8,7.5,7.5,6.5,6,6,7,7.5,1.5,6, // A-J
        7.5,5.5,8,7.5,8,8,8,8,7.25,8, // K-T
        7,8,7.5,8,8,7.5]; // U-Z

function sumLwds(A,start,end,value=0) =
  (start > end) ? 0 : (start == end ? value + lwds[A[start]] : sumLwds(A,start+1,end,value+lwds[A[start]]));

module ltr(id, showBlocks=false){
	if(showBlocks){ // purely for debugging purposes; render will only render the blocks
		translate([0,0,-0.5]) color("black") square([lwds[id],10]);
	}
    if(id == 1){ // A
        difference(){
            polygon([[0,0], [3.25,10], [4.75,10], [8,0], [6.375,0],
                    [5.625,2.5], [2.375,2.5], [1.625,0]]);
            polygon([[2.875,4],[4,7.5],[5.125,4]]);
        }
    }
    if(id == 2){ // B
        difference(){
            union(){
                square([4.75,10]);
                translate([4.5,7.25]) circle(r=2.75);
                translate([4.5,3]) circle(r=3);
            }
            translate([4.5,7.25]) circle(r=1.25);
            translate([4.5,3]) circle(r=1.5);
            translate([1.5,6]) square([3,2.5]);
            translate([1.5,1.5]) square([3,3]);
        }
    }
    if(id == 3){// C
        difference(){
            translate([4,5]) scale([4/5,1]) circle(r=5);
            translate([4,5]) scale([3.5/5,3.75/4]) circle(r=3.5);
            polygon([[4,3.5],[4,6.5],[9,6.5],[9,3.5]]);
        }
    }
    if(id == 4){// D
        difference(){
            union(){
                square([1.5,10]);
                translate([1.5,5]) circle(r=5);
            }
            difference(){
                translate([1.5,5]) circle(r=3.5);
                square([1.5,10]);
            }
            translate([-5,0]) square([5,10]);
        }
    }
    if(id == 5){// E
            polygon([[0,0], [0,10], [6,10], [6,8.5],
                    [1.5,8.5], [1.5,5.75], [4.75,5.75],
                    [4.75,4.25], [1.5,4.25], [1.5,1.5],
                    [6,1.5], [6,0]]);
    }
    if(id == 6){// F
            polygon([[0,0], [0,10], [6,10], [6,8.5],
                     [1.5,8.5], [1.5,5.5], [4.75,5.5],
                    [4.75,4], [1.5,4], [1.5,0]]);
    }
    if(id == 7){// G
        union(){
            difference(){
                translate([4,5]) scale([4/5,1]) circle(r=5);
                translate([4,5]) scale([3.5/5,3.75/4]) circle(r=3.5);
                polygon([[4,4.5],[4,6.5],[8,10],[9,4.5]]);
                translate([7,1.5]) square([1.5,3.5]);
            }
            translate([4,3.25]) square([3,1.5]);
            translate([5.5,1.75]) square([1.5,3]);
        }
    }
    if(id == 8){ // H
        difference(){
            polygon([[0,0], [0,10], [1.5,10], [1.5,5.75], [6,5.75],
                     [6,10], [7.5,10],
                     [7.5,0], [6,0], [6,4.25], [1.5,4.25], [1.5,0]]);
        }
    }
    if(id == 9){ // I
		square([1.5,10]);
    }
    if(id == 10){// J
        translate([4.5,3]) square([1.5,7]);
        translate([0,3]) square([1.5,0.5]);
        difference(){
            translate([3,3]) circle(r=3);
            translate([3,3]) circle(r=1.5);
            translate([-0.5,3]) square([8,8]);
        }
//        // Alternate form, with cross on top
//        translate([0,2.25]) square([1.5,1]);
//        polygon([[3,2.25], [3,8.5], [0,8.5], [0,10], [6,10], [6,8.5],
//                [4.5,8.5],[4.5,2.25]]);
//        difference(){
//            translate([2.25,2.25]) circle(r=2.25);
//            translate([2.25,2.25]) circle(r=0.75);
//            translate([-0.5,2.25]) square([8,8]);
//        }
    }
    if(id == 11){// K
		polygon([[0,0], [0,10], [1.5,10],
				[1.5,5.875],[5.75,10],[7.5,10],
				[3.5,6],[7.5,0],[5.75,0],[2.5,5],
				[1.5,4],[1.5,0]]);
    }
    if(id == 12){// L
        polygon([[0,0], [0,10], [1.5,10], [1.5,1.5],
                [5.5,1.5], [5.5,0]]);
    }
    if(id == 13){ // M
		polygon([[0,0], [0,10], [1.5,10], [3.5,6], [4,6], [6,10], [7.5,10], [7.5,0],
				[6,0], [6,7], [4.5,4], [3,4], [1.5,7], [1.5,0]]);
    }
    if(id == 14){// N
        polygon([[0,0], [1.5,0], [1.5,7.25], [6,0], 
                 [7.5,0], [7.5,7.75], [7.5,10], [6,10],
                 [6,2.75], [1.5,10],[0,10]]);
    }
    if(id == 15){// O
		difference(){
			translate([4,5]) scale([4/5,1]) circle(r=5);
			translate([4,5]) scale([3.5/5,3.75/4]) circle(r=3.5);
		}
    }
    if(id == 16){// P
        difference(){
            union(){
                polygon([[0,0], [0,10], [4.75,10], 
                        [4.75,4], [1.5,4], [1.5,0]]);
                translate([4.5,7]) circle(r=3);
            }
            translate([4.5,7]) circle(r=1.5);
            translate([1.5,5.5]) square([3,3]);
        }
    }
    if(id == 17){// Q
        union(){
            difference(){
                translate([4,5]) scale([4/5,1]) circle(r=5);
                translate([4,5]) scale([3.5/5,3.75/4]) circle(r=3.5);
            }
            polygon([[8,0], [6.375,0],
                    [4.25,2.5],[4.875,4]]);
        }
    }
    if(id == 18){// R
        difference(){
            union(){
                polygon([[0,0], [0,10], [1.5,10], [4.5,10], [5.5,4],
                        [7,0], [5.5,0], [4,4], [1.5,4], [1.5,0]]);
                translate([4.5,7]) circle(r=3);
            }
            translate([4.5,7]) circle(r=1.5);
            translate([1.5,5.5]) square([3,3]);
        }
    }
    if(id == 19){// S
        // height 10, so r = 11.5/4
        union(){
            translate([3.625,10-11.5/4]) difference(){
                scale([5/4,1]) circle(r=11.5/4);
                scale([5/4,1]) circle(r=11.5/4-1.5);
                translate([0,-6]) square([6,6]);
            }
            translate([3.625,11.5/4]) difference(){
                scale([5/4,1]) circle(r=11.5/4);
                scale([5/4,1]) circle(r=11.5/4-1.5);
                translate([-6,0]) square([6,6]);
            }
        }
    }
    if(id == 20){// T
        polygon([[3.25,0], [3.25,8.5], [0,8.5], [0,10], [8,10], [8,8.5],
                [4.75,8.5],[4.75,0]]);
    }
    if(id == 21){// U
		union(){
			difference(){
				translate([3.5,3.5]) circle(r=3.5);
				translate([3.5,3.5]) circle(r=2);			
				translate([-1,3.5]) square([9,5]);
			}
			translate([0,3.5]) square([1.5,6.5]);
			translate([5.5,3.5]) square([1.5,6.5]);
		}
		
    }
    if(id == 22){ // V
        difference(){
            polygon([[0,10], [3.25,0], [4.75,0], [8,10], [6.375,10],
                    [4,2.5], [1.625,10]]);
        }
    }
    if(id == 23){// W
		polygon([[0,10], [1.75,0], [3.25,0], [4,3], [4.75,0], [6.25,0], [8,10],
				[6.5,10], [5.25,3], [4.75,5], [3.25,5], [2.75,3], [1.5,10]]);

    }
    if(id == 24){// X
        //alternate / hopefully identical construction; horizontal separation of 1.75
        //polygon([[0,0], [6.25,10], [8,10], [1.75,0]]);
        //polygon([[0,10], [6.25,0], [8,0], [1.75,10]]);
        polygon([[0,0], [3.125,5], [0,10], [1.75,10],
                 [4,6.4], [6.25,10], [8,10], [4.875,5],
                 [8,0], [6.25,0], [4,3.6], [1.75,0]]);
    }
    if(id == 25){// Y
        polygon([[3.25,0], [3.25,4.75], [0,10], [1.75,10],
                 [4,6.4], [6.25,10], [8,10],
                 [4.75,4.75], [4.75,0]]);
    }
    if(id == 26){// Z
        polygon([[0,0], [0,1.5], [5.5,8.5], [0,8.5], 
                 [0,10], [6.25,10], [7.5,10], [7.5,8.5],
                 [2,1.5], [7.5,1.5],[7.5,0]]);
    }
}

module printLetters(letterArray, gap=0.5, showBlocks=false){
	for(i = [0:(len(letterArray)-1)]){
		translate([sumLwds(letterArray,0,i-1)+i*gap,0]) ltr(letterArray[i], showBlocks);
	}
}

//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//12345678901234567890123456

//FOXY KNUTH ZAPS A FEW
/*
letters1=[6,15,24,25,0, 11,14,21,20,8,0, 26,1,16,19,0, 1,0, 6,5,23];
//GOOD CAB JAM DRIVERS
letters2=[7,15,15,4,0, 3,1,2,0, 10,1,13,0, 4,18,9,22,5,18,19];


linear_extrude(height=2, center=true){
	printLetters(letters1);
	translate([0,-11]) printLetters(letters2);
}
*/

letters1=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26];
letters1K=[11];


difference () {
	scale([1, 1.3, 1]) translate([0.1, 0.1, -5]) rotate([90, 0, 90]) linear_extrude(height=300){
			printLetters(letters1K);
	}

	linear_extrude(height=1000, center=true){
		difference() {
			square([1000, 10]);
			printLetters(letters1);
		}
	}
}