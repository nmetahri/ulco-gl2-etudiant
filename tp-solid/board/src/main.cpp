
#include "Board.hpp"
#include "NumBoard.hpp"
#include "ReportFile.hpp"
#include "ReportStdout.hpp"

void testBoard(Board & b, ReportFile &fileReporter, const ReportStdout &reporter) {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");

    reporter.report(b); 
    fileReporter.report(b);
}

void testNumBoard(NumBoard & b, ReportFile &fileReporter, const ReportStdout &reporter) {
    std::cout << b.getTitle() << std::endl;
    b.addNum("item 1");
    b.addNum("item 2");

    reporter.report(b); 
    fileReporter.report(b);
}


int main() {
    ReportFile fileReporter("tmp.txt");
    ReportStdout reporter;

    Board b1;
    testBoard(b1, fileReporter, reporter);

    NumBoard b2;
    testNumBoard(b2, fileReporter, reporter);
    testBoard(b2, fileReporter, reporter);

    return 0;
}

