#ifndef DataFormats_PCaloHitWithPosition_h
#define DataFormats_PCaloHitWithPosition_h

#include <vector>
#include "SimDataFormats/CaloHit/interface/PCaloHit.h"
#include "RecoLocalCalo/HGCalRecAlgos/interface/RecHitTools.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/Common/interface/Ptr.h"

class PCaloHitWithPosition {
    public:
        // Constructor & destructor (default needed)
        inline PCaloHitWithPosition() {}
        // inline PCaloHitWithPosition(const PCaloHit * fHit) { hit_ = fHit; }
        inline PCaloHitWithPosition(edm::Ptr<const PCaloHit> fHit){ hit_ = fHit; }
        virtual ~PCaloHitWithPosition() {};

        // const PCaloHit * hit() const { return hit_; }
        edm::Ptr<const PCaloHit> hit() const { return hit_; }

        void setPositionVars(hgcal::RecHitTools * hgcalRecHitToolInstance){
            DetId id = hit()->id();
            position_ = hgcalRecHitToolInstance->getPosition(id);
            zside_ = hgcalRecHitToolInstance->zside(id);
            siThickness_ = hgcalRecHitToolInstance->getSiThickness(id);
            radiusToSide_ = hgcalRecHitToolInstance->getRadiusToSide(id);
            siThickIndex_ = hgcalRecHitToolInstance->getSiThickIndex(id);
            layer_ = hgcalRecHitToolInstance->getLayer(id);
            layerWithOffset_ = hgcalRecHitToolInstance->getLayerWithOffset(id);
            wafer_ = hgcalRecHitToolInstance->getWafer(id);
            cell_ = hgcalRecHitToolInstance->getCell(id);
            isHalfCell_ = hgcalRecHitToolInstance->isHalfCell(id);
            isSilicon_ = hgcalRecHitToolInstance->isSilicon(id);
            eta_ = hgcalRecHitToolInstance->getEta(id);
            phi_ = hgcalRecHitToolInstance->getPhi(id);
            pt_ = hgcalRecHitToolInstance->getPt(id, hit()->energy());            
            }

    private:
        // const PCaloHit * hit_;
        edm::Ptr<const PCaloHit> hit_;
        // const PCaloHit> hit_;

        GlobalPoint position_;
        int zside_;
        std::float_t siThickness_;
        std::float_t radiusToSide_;
        int siThickIndex_;
        unsigned int layer_;
        unsigned int layerWithOffset_;
        std::pair<int, int> wafer_;
        std::pair<int, int> cell_;
        bool isHalfCell_;
        bool isSilicon_;
        float eta_;
        float phi_;
        float pt_;
    };

typedef std::vector<PCaloHitWithPosition> PCaloHitWithPositionCollection;

#endif