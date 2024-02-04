// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    
    double exam_tot = 0;
    double fn_exam = 0;
    double hw_tot = 0;
    int num_hw = 0;
    double lw_tot = 0;
    int num_lw = 0;
    double read_tot = 0;
    int num_read = 0;
    double enga_tot = 0;
    int num_enga = 0;
    int num_pg_check = 0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            exam_tot += score;
            
        } else if (category == "final-exam") {
            // TODO(student): process final score
            fn_exam += score;
            
        } else if (category == "hw") {
            // TODO(student): process hw score
            hw_tot += score;
            num_hw += 1;
        } else if (category == "lw") {
            // TODO(student): process lw score
                
            lw_tot += score * 100;
            num_lw += 1;
            
        } else if (category == "reading") {
            // TODO(student): process reading score
            read_tot += score;
            num_read += 1;

        } else if (category == "engagement") {
            // TODO(student): process engagement score
            enga_tot += score;
            num_enga += 1;
        }else if  (category == "program-check") {
            // TODO(student): process program-check score

            num_pg_check += score;

        }else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages
    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double reading = 0;
    double engagement = 0;

    
    exam_average = (exam_tot + fn_exam ) / 3;

    if (fn_exam > exam_average) {
        exam_average = fn_exam;
    }

    if (num_hw >= 1) {
        
        hw_average = (hw_tot / num_hw);
        
    } 

    if (num_lw >= 1) {
        lw_average = (lw_tot / num_lw) ;
        if (num_pg_check == 0){
            lw_average = lw_average * 0.5;
        } else if (num_pg_check == 1){
            lw_average = lw_average * 0.75;
        }
    }

    if (num_read >= 1) {
        reading = (read_tot / num_read );
        

    } 
    reading += 15.0; 

    if (reading > 100) {
        reading = 100;
    }

    if (num_enga >= 1) {
        engagement = (enga_tot / num_enga) ;
        
    }
    engagement += 15.0;
    if (engagement > 100){
        engagement = 100;
    }
    // TODO(student): compute weighted total of components
    double weighted_total = 0;
    weighted_total = ((exam_average*0.40) + (hw_average*0.40) + (lw_average*0.10) + (reading*0.05) + (engagement*0.05));
    
    
    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if (weighted_total < 60) {
        final_letter_grade = 'F';
    } else if ((weighted_total < 70.0) && (weighted_total >= 60.0)) {
        final_letter_grade = 'D';
    } else if ((weighted_total >= 70.0) && (weighted_total < 80.0)) {
        final_letter_grade = 'C';
    } else if ((weighted_total >= 80.0) && (weighted_total < 90.0)) {
        final_letter_grade = 'B';
    } else if (weighted_total >= 90.0) {
        final_letter_grade = 'A';
    }
    

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement | program-check" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
