#ifndef MuPMTSD_h
#define MuPMTSD_h 1

#include "G4DataVector.hh"
#include "G4VSensitiveDetector.hh"
#include "MuPMTHit.hh"

#include <fstream>

class G4Step;
class G4HCofThisEvent;

class MuPMTSD : public G4VSensitiveDetector
{

  public:




    MuPMTSD(G4String name);
    virtual ~MuPMTSD();
 
    virtual void Initialize(G4HCofThisEvent* );
    virtual G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* );
 
    //A version of processHits that keeps aStep constant
    G4bool ProcessHits_constStep(const G4Step* ,
                                 G4TouchableHistory* );
    virtual void EndOfEvent(G4HCofThisEvent* );
    virtual void clear();
    void DrawAll();
    void PrintAll();
 
    //Initialize the arrays to store pmt possitions
    inline void InitPMTs(G4int nPMTs){
      if(fPMTPositionsX)delete fPMTPositionsX;
      if(fPMTPositionsY)delete fPMTPositionsY;
      if(fPMTPositionsZ)delete fPMTPositionsZ;
      fPMTPositionsX=new G4DataVector(nPMTs);
      fPMTPositionsY=new G4DataVector(nPMTs);
      fPMTPositionsZ=new G4DataVector(nPMTs);
    }

    //Store a SiPM position
    inline void SetPMTPos(G4int n,G4double x,G4double y,G4double z){
      if(fPMTPositionsX)fPMTPositionsX->insertAt(n,x);
      if(fPMTPositionsY)fPMTPositionsY->insertAt(n,y);
      if(fPMTPositionsZ)fPMTPositionsZ->insertAt(n,z);
    }

  private:

    MuPMTHitsCollection* fPMTHitCollection;

    G4DataVector* fPMTPositionsX;
    G4DataVector* fPMTPositionsY;
    G4DataVector* fPMTPositionsZ;
};

#endif
