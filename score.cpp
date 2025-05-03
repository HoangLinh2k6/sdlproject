#include <string>
#include <fstream>

#include "score.h"

Score::Score( SDL_Renderer* ren, const char* text, int _size ):
    font{ ren, text, _size }
{
    checkAndCreateFile();
    getHighScoreFromFile();
}

void Score::checkAndCreateFile(){
    std::ifstream file( HIGHSCORE );
    if( !file ){
        std::ofstream newFile( HIGHSCORE );
        newFile << 0;
        newFile.close();
    }
}

void Score::getHighScoreFromFile() {
    std::ifstream file(HIGHSCORE);
    if( file >> highScore ) {
        return;
    }
}

void Score::updateScore(){
    score ++;
}

void Score::updateHighScore(){
    if( score > highScore ){
        std::ofstream file( HIGHSCORE );
        file << score;
    }
}

void Score::renderScore( int x, int y ){
    font.createTexture( getScore() );
    font.render( x, y );
}

void Score::renderHighScore( int x, int y ){
    font.createTexture( getHighScore() );
    font.render( x, y );
}

void Score::resetHighScore(){
    std::ofstream file( HIGHSCORE, std::ios::trunc );
    if( file ){
        file << 0 << std::endl;
    }
    updateHighScore();
}

const char* Score::getScore(){
    std::string scoreText;
    scoreText = "Score: " + std::to_string( score );
    return scoreText.c_str();
}

const char* Score::getHighScore(){
    std::string scoreText;
    scoreText = "High Score: " + std::to_string( highScore );
    return scoreText.c_str();
}

void Score::quit(){
    font.free();
}
