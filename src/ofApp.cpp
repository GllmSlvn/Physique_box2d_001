#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    
    // setup gui
    gui.setup();
    gui.add(densitySlider.setup("Density", 3.0, 0., 100.));
    gui.add(bounceSlider.setup("Bounce", 0.53, 0., 10.));
    gui.add(frictionSlider.setup("Friction", 0.1, 0., 100.));
    gui.add(gravitySlider.setup("gravity", ofVec2f(0,8), ofVec2f(0,0), ofVec2f(20,20)));
    
    // box2d init !
    box2d.init();
    //box2d.setGravity(0, 8);
    box2d.setGravity(0, 8);
    box2d.createGround();
    box2d.setFPS(60.0);
    box2d.registerGrabbing();
    
    // make the shape
    box2dEdge.setPhysics(0.0, 0.5, 0.5);
    box2dEdge.create(box2d.getWorld());
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
    
    box2d.setGravity(gravitySlider->x, gravitySlider->y);
    
    // remove shapes offscreen
    ofRemove(rects, ofxBox2dBaseShape::shouldRemoveOffScreen);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(auto &rect : rects) {
        ofFill();
        ofSetColor(255);
        rect->draw();
    }
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'p'){
        rects.clear();
    }
    
    if(key == 'z'){
        float w = ofRandom(4, 50);
        float h = ofRandom(4, 50);
        
        for(int i = 0; i < 10; i++){
            auto rect = make_shared<ofxBox2dRect>();
            //rect->setPhysics(3.0, 0.53, 0.1);
            rect->mesh;
            rect->setPhysics(densitySlider, bounceSlider, frictionSlider);
            rect->setup(box2d.getWorld(), ofGetMouseX(), ofGetMouseY(), w, h);
            rects.push_back(rect);
        }
    }
    
    if(key == '1'){
        for(auto &rect : rects){
            rect->setPhysics(1, 1, 1);
        }
    }
    if(key == '2'){
        for(auto &rect : rects){
            rect->setPhysics(0.5, 0.5, 0.5);
        }
    }
    if(key == '3'){
        for(auto &rect : rects){
            rect->setPhysics(3, 0.1, 0.1);
        }
    }
    if(key == '4'){
        for(auto &rect : rects){
            rect->setPhysics(5, 0.9, 0.2);
        }
    }
    if(key == '5'){
        for(auto &rect : rects){
            rect->setPhysics(2, 0.3, 0.9);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
   
   
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
