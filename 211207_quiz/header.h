#define MAX_NAME_LENGTH 250
#define MAX_REGD_LENGTH 20
#define MAX_QUIZZES 100



struct QuizResult {
	                char name[MAX_NAME_LENGTH];
			                int regdNo;
					                int score;
};


int enterUserName(char *name);
void sortLeaderboard(struct QuizResult leaderboard[], int numQuizzes);
int input_run_quiz(char* filename);
void writeResultsToFile(struct QuizResult leaderboard[], int numQuizzes);
int userAlreadyExists( const int regd_no);
                                                                                                                                                                                               
                                                                                                                                                                                               
                                                                                                                                                                                              
                                                                                                                                                                                               
                                                                                                                                                                                               
                                                                                                                                                                                               
                                                                                                                                                                                               
                                                                                                                                                                                               
                                                                                                                                                                                               
                                                                                                                                                                                               
                                                                                                                                                                                               
                                                                                                                                                                                               
                                                                                             
