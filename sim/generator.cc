#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1); //jumlah sumber tembakan particle
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	//generate jenis sinar yang dipancarkan (mu+ dan mu-)
	
	G4double size = 5;
	//random seed - random seed karena gk tau cara buat seed minus
	G4double x0 = size*(G4UniformRand()-G4UniformRand());
	G4double y0 = size*(G4UniformRand()-G4UniformRand());
	G4cout << "posisi x,y partikel" <<std::endl;
	G4cout << x0 <<","<< y0 <<std::endl;
	
	G4ThreeVector pos(x0*m,y0*m,-5*m); //posisi awal partikel
	//sumbu z dibuat statik sebagai penanda area tembak
	G4ThreeVector mom(0,0,100); //momentum partikel
	
	fParticleGun->SetParticlePosition(pos); //posisi awal partikel
	fParticleGun->SetParticleMomentumDirection(mom); //arah momentum 
	fParticleGun->SetParticleMomentum(100*GeV); //besar momentum
	fParticleGun->SetParticleDefinition(G4MuonPlus::Definition()); //partikel yang dipakai
	
	fParticleGun->GeneratePrimaryVertex(anEvent);
	
	
}
