//Computer orders generator - this program generates random for a computer or whole PC setup, made of new or used parts, in a certain budget, with certain purpose, meeting certain requirements, with certain features
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
// program creates a function which chooses whether this PC order will be made of a computer only or computer with all peripherals
string func1(int b) {
    switch(b){
        case 1:
        return("PC");
        break;
        case 2:
        return("PC + peripherals");
        break;
        default:
        return("PC");
    }
}
// program creates a function which chooses whether PC has to be made of new parts only or can be made of used parts too
string func2(int c) {
    switch(c){
        case 1:
        return("only new parts");
        break;
        case 2:
        return("new parts or used parts");
        break;
        default:
        return("only new parts");
    }
}
// program creates a function which chooses a purpose of ordered PC
string purpose(int d, int a) {
    switch(d){
        case 1:
        return("gaming");
        break;
        case 2:
        return("productivity");
        break;
        case 3:
        return("streaming");
        break;
        case 4:
        if(a <= 3000) {
            return("NAS");
        } else {
            return("mixed");
        } break;
        case 5:
        if(a <= 3000) {
            return("office tasks");
        } else {
            return("mixed");
        } break;
        case 6:
        return("mixed");
        break;
        case 7:
        if(a <= 3000) {
            return("HTPC");
        } else {
            return("mixed");
        } break;
        case 8:
        return("mixed");
        break;
        default:
        return("mixed");
    } 
}
// program creates a function which chooses type of games this PC should be optimized for if its purpose is gaming, or type of professional tasks this PC should be optimized for if its purpose is professional workload
string priority2(int e, int d){
    switch(e) {
        case 1:
        switch(d) {
            case 1:
            return("RTS games");
            break;
            case 2:
            return("photo editing");
            break;
            default:
            return(" ");
        } break;
        case 2:
        switch(d) {
            case 1:
            return("racing games");
            break;
            case 2:
            return("2D modeling");
            break;
            default:
            return(" ");
        } break;
        case 3:
        switch(d) {
            case 1:
            return("FPS games");
            break;
            case 2:
            return("Video editing");
            break;
            default:
            return(" ");
        } break;
        case 4:
        switch(d) {
            case 1:
            return("RPG games");
            break;
            case 2:
            return("programming");
            break;
            default:
            return(" ");
        } break;
        case 5:
        switch(d) {
            case 1:
            return("newest AAA titles in 4k");
            break;
            case 2:
            return("mixed");
            break;
            default:
            return(" ");
        } break;
        case 6:
        switch(d) {
            case 1:
            return("mixed");
            break;
            case 2:
            return("mixed");
            break;
            default:
            return(" ");
        } break;
        case 7:
        switch(d) {
            case 1:
            return("newest AAA titles in 1080p");
            break;
            case 2:
            return("animations making");
            default:
            return(" ");
        } break;
        case 8:
        switch(d) {
            case 1:
            return("e-sports titles");
            break;
            case 2:
            return("AI / machine learning");
            default:
            return(" ");
        } break;
        case 9:
        switch(d) {
            case 1:
            return("open world games");
            break;
            case 2:
            return("music production");
            default:
            return(" ");
        } break;
        case 10:
        switch(d) {
            case 1:
            return("newest AAA titles in 1440p");
            break;
            case 2:
            return("CAD");
            default:
            return(" ");
        } break;
        case 11:
         switch(d) {
            case 1:
            return("mixed");
            break;
            case 2:
            return("3D modeling");
            default:
            return(" ");
        } break;
        default:
        return(" ");
    } 
}
// program creates a function which defines requirements regarding loudness of that PC
string noise(int g) {
    switch(g) {
        case 1:
        return("it's neutral for me");
        break;
        case 2:
        return("it should be as quiet as possible");
        break;
        case 3:
        return("not too loud, but it doesn't have to be really quiet");
        break;
        case 4:
        return("i play with headphones");
        break;
        case 5:
        return("every additional db is painful");
        break;
        case 6:
        return("it's neutral for me");
        break;
        case 7:
        return("it's neutral for me");
        break;
        default:
        return("it's neutral to me");
    }
}
// program creates a function which defines requirements regarding workload temperatures of this PC
string cooling(int h) {
    switch(h){
        case 1:
        return("it must be as cool as possible");
        break;
        case 2:
        return("it's neutral for me");
        break;
        case 3:
        return("if it won't achieve temperature of sun, i will be satisfied");
        break;
        case 4:
        return("it's neutral for me");
        break;
        default:
        return("it's neutral to me");
    }
}
// program creates a function which defines requirements regarding size of this PC  
string size(int l) {
    switch(l){
        case 1:
        return("as small as possible");
        break;
        case 2:
        return("small PCs are nice, but temperatures are more important");
        break;
        case 3:
        return("small, but not too small");
        break;
        case 4:
        return("i like normal-sized PCs");
        break;
        case 5:
        return("small PCs are nice, but cost is more important");
        break;
        case 6:
        return("it's neutral for me");
        break;
        case 7:
        return("i like normal-sized PCs");
        break;
        case 8:
        return("it's neutral for me");
        break;
        default:
        return("it's neutral to me");
    }
}
// program creates a function which defines requirements regarding aesthetics of this PC
string aesthetics(int i) {
    switch(i){
        case 1:
        return("Black theme with lots of RGB");
        break;
        case 2:
        return("Black theme without RGB");
        break;
        case 3:
        return("White theme without RGB");
        break;
        case 4:
        return("Black theme with some RGB");
        break;
        case 5:
        return("White theme with some RGB");
        break;
        case 6:
        return("it isn't important to me");
        break;
        case 7:
        return("it isn't important to me");
        break;
        case 8:
        return("White theme with lots of RGB");
        break;
        default:
        return("it isn't important to me");
    }
}
// program creates a function which defines if this PC should have better specs, looks or workload noise and if this PC setup should have better PC specs, monitor or peripherals   
string priority(int m, int b) {
    switch(m){
        case 1:
        switch(b) {
            case 1:
            return("better specs");
            break;
            case 2:
            return("better PC");
            break;
            default:
            return("none");
        } break;
        case 2:
        switch(b) {
            case 1:
            return("better looks");
            break;
            case 2:
            return("better monitor");
            break;
            default:
            return("none");
        } break;
        case 3:
        switch(b) {
            case 1:
            return("better silence");
            break;
            case 2:
            return("better peripherals");
            break;
            default:
            return("none");
        } break;
        default:
        return("none");
    }
}
// program creates a function which defines if certain peripherals of this setup should be wired or wireless (if this PC is ordered with peripherals)
string peripherals(int r, int b){
    if(b == 2) {
        switch(r){
            case 1:
            return("all peripherals wired");
            break;
            case 2:
            return("mouse wireless, other peripherals wired");
            break;
            case 3:
            return("mouse and keyboard wireless, headphones wired");
            break;
            case 4:
            return("all peripherals wireless");
            break;
            case 5:
            return("all peripherals wired");
            break;
            case 6:
            return("it's neutral for me");
            break;
            case 7:
            return("it's neutral for me");
            break;
            default:
            return("it's neutral for me");
        }
    } else {
        return("no peripherals");
    }
}
// program creates a function which chooses if this PC should have certain features    
string special_wishes(int j, int k, int b) {
    if(j == 1 || k == 1) {
        return("none");
    } else if(j == 2 || k == 2) {
        return("minimum 2tb of system memory");
    } else if(j == 3 || k == 3) {
        return("minimum 3tb of system memory");
    } else if(j == 4 || k == 4) {
        return("minimum 16gb of ram");
    } else if(j == 5 || k == 5) {
        return("none");
    } else if((j == 6 && b == 2) || (k == 6 && b == 2)) {
        return("ultrawide monitor");
    } else if((j == 7 && b == 2) || (k == 6 && b == 2)) {
        return("monitor with 144 hz of refresh rate");
    } else if(j == 8 || k == 8) {
        return("none");
    } else if((j == 9 && b == 2) || (k == 9 && b == 2)) {
        return("monitor with 4k resolution");
    } else if(j == 10 || k == 10) {
        return("more than 1tb of system memory");
    } else if(j == 11 || k == 11) {
        return("none");
    } else if(j == 12 || k == 12) {
        return("none");
    } else if(j == 13 || k == 13) {
        return("minimum 32gb of RAM");
    } else if((j == 14 && b == 2) || (j == 14 || b == 2)) {
        return("monitor with wqhd resolution");
    } else if(j == 15 || k == 15) {
        return("support for Ray Tracing");
    } else if((j == 16 && b == 2) || (k == 16 && b == 2)) {
        return("two monitors");
    } else if((j == 17 && b == 2) || (k == 16 && b == 2)) {
        return("three monitors");
    } else if(j == 18 || k == 18) {
        return("only SSD storage");
    } else if(j == 19 || k == 19) {
        return("none");
    } else if(j == 20 || k == 20) {
        return("none");
    } else if(j == 21 || k == 21) {
        return("none");
    } else if(j == 22 || k == 22) {
        return("none");
    } else if((j == 23 && b == 2) || (k == 23 && b == 2)) {
        return("monitor with 240 hz of refresh rate");
    } else if(j == 24 || k == 24) {
        return("none");
    } else {
        return("none");
    }
}
// program creates a function which defines whether this PC should be capable of overclocking
string overclocking(int h) {
    switch(h){
        case 1:
        return("I want to OC");
        break;
        case 2:
        return("I don't want to OC");
        break;
        case 3:
        return("it's neutral for me");
        break;
        case 4:
        return("it's neutral for me");
        break;
        default:
        return("it's neutral for me");
    }
}
// program creates a bunch of randomly generated numbers which will be useful for order generation
int main() {
    srand(time(0));
    int a = (rand()%17000)+1000;
    int b = (rand()%2)+1;
    int c = (rand()%2)+1;
    int d = (rand()%8)+1;
    int e = (rand()%13)+1;
    int g = (rand()%7)+1;
    int h = (rand()%4)+1;
    int i = (rand()%8)+1;
    int j = (rand()%23)+1;
    int k = (rand()%23)+1;
    int l = (rand()%8)+1;
    int m = (rand()%3)+1;
    int r = (rand()%7)+1;
    // program puts randomly generated numbers into previously created functions and outputs randomly generated PC order
    cout << "price:\n" << a << "\n\n" << func1(b) << "\n" << func2(c) << "\n\npurpose:\n" << purpose(d,a) << "\n" << priority2(e,d) << "\n\npriority:\n" << priority(m,b) << "\n\nnoise:\n" << noise(g) << "\n\ncooling:\n" << cooling(h) << "\n\naesthetics:\n" << aesthetics(i) << "\n\nsize:\n" << size(l) << "\n\npriority:\n" << priority(m,b) << "\n\nperipherals:\n" << peripherals(r,b) << "\n\nOC:\n" << overclocking(h) << "\n\nspecial wishes:\n" << special_wishes(j,k,b);
    return 0;
}