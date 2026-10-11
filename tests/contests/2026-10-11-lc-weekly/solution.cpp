// LC Weekly 2026-10-11 — Q3 · BusBooking  (THE weekend upsolve)
// Statement + both gates: ./statement.md     Gate answers: ./gate.md
//
// =====================================================================
//  PART 0 — THE LANGUAGE FACT  (CPP_GAPS #19, told, not derived)
//  This is the only thing you were missing in the contest. Read it once
//  on a NEUTRAL example, then close this comment and never look again.
// =====================================================================
//
//   class Counter {              // a class = state that SURVIVES between calls
//   private:                     // private  = only the class's own code may touch it
//       int total;               //   <-- MEMBER VARIABLES. They live as long as the
//       vector<int> seen;        //       object lives. This is the whole point.
//
//   public:                      // public   = what the judge is allowed to call
//       Counter(int n) {         //   <-- CONSTRUCTOR: same name as the class, no
//           total = 0;           //       return type. Runs ONCE, when the object is
//           seen.assign(n, 0);   //       created. Size your containers here.
//       }
//
//       void add(int x) {        //   <-- a METHOD. Reads/writes members with no
//           total += x;          //       arguments passed and nothing returned —
//           seen[x] = 1;         //       that is what makes it different from a
//       }                        //       free function.
//
//       int get() {              //   <-- another method, same members
//           return total;
//       }
//   };                           //   <-- the semicolon. Yes, really.
//
//   The judge writes:   Counter* c = new Counter(5);  c->add(3);  c->get();
//   You never write that line. You only fill the class.
//
//   That is 100% of the syntax. There is no inheritance here, no virtual,
//   no templates. A design problem is a struct plus some functions.
//
// =====================================================================
//  PART 1 — NOW THE ACTUAL THINKING. All of it is yours.
// =====================================================================

class BusBooking {
private:
    // Q1. What is the SMALLEST amount of state that lets every method answer
    //     in its budget? Write the list here before you write any code.
    //     Ask of each candidate: "if I don't store this, which method breaks?"
    //
    //     Prompts, not answers:
    //       - What do you need to know about a single row?  How many bits is that?
    //       - getTotalTime() is called up to 10^5 times. Re-deriving the answer
    //         each call costs what?  So where must the answer LIVE?
    //       - The Note says a booked seat's cost is FROZEN at booking time.
    //         What does that force you to remember, and for how long?
    //       - getMinTime(): trace Example 1's four seats, then Example 2's one
    //         seat. Write down the min for each. Now stare at those two numbers
    //         next to the number of booked seats. What do you notice?
    //         (Do this on paper BEFORE you write a single member here.)


public:
    BusBooking(int n) {
        // Q2. What has to be true the instant the object exists?
        //     Which of your members needs sizing, and to what — n or n+1? Why?
    }

    void toggle(string seat) {
        // Q3. First: turn "D20" into something you can index with.
        //     Which character is the letter? Which characters are the number?
        //     (C++ fact if you need it: stoi(s.substr(1)) parses the tail.)
        //
        // Q4. This method has exactly two branches. Name them in words first.
        //
        // Q5. The booking branch: what decides 1 vs 3? State it as a condition
        //     on your stored state, not in English about buses.
        //
        // Q6. The freeing branch: the Note is the whole trap here. When you free
        //     a seat, what EXACTLY do you subtract? Re-read the Example 2 trace
        //     (free D7 removes 3, free C7 removes 1) and say why you cannot
        //     recompute that number at freeing time.
        //
        // Q7. Does freeing a middle seat change the cost of an already-booked
        //     window seat next to it? Quote the Note in your answer.
    }

    int getTotalTime() {
        // Q8. If you answered Q1 honestly, this method is one line. Is it?
        //     If it is a loop, go back to Q1 and re-read your budget.
    }

    int getMinTime() {
        // Q9. State the claim you found on paper as a sentence with the word
        //     "always" or "never" in it. Then try to BREAK it: build a row where
        //     you think an unavoidable delay exists. Can you actually build one?
        //     Why not? That argument IS the solution — write it in gate.md.
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
