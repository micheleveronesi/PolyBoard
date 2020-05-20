#ifndef SCACCHI_H
#define SCACCHI_H
#include "gioco.h"
#include "../colore.h"
#include "../pedina/scacchi/pedone.h"
#include "../pedina/scacchi/torre.h"
#include "../pedina/scacchi/alfiere.h"
#include "../pedina/scacchi/cavallo.h"
#include "../pedina/scacchi/regina.h"
#include "../pedina/scacchi/re.h"
#include "../tipogioco.h"

class Scacchi : public Gioco {
private:
    bool scaccoAlRe(Colore re) const;
    bool scaccoMatto(Colore re) const;
    bool arrocco(const Posizione& re, const Posizione& finale);
    static Pedina* idToPedina(const ID&);
public:
    Scacchi();
    virtual TipoGioco tipoGioco() const;
    virtual bool mossa(const Posizione& posIniziale, const Posizione& posFinale);
    virtual void cambioTurno();
    virtual bool controlloVincitore() const;
    virtual Scacchi* clone() const;
    bool verificaPromozionePedone(const Posizione&) const;
    void promozionePedone(char pedinaSel, const Posizione& posFinale);
    virtual void inserisciPedina(const Posizione&, const ID&);
};
#endif