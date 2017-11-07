#!/bin/bash
BIN_GEN_QM=/home/susu/Qt5.4.1/5.4/gcc_64/bin/./lrelease
DIR_SRCS=/home/susu/Desktop/SVN_HKMC/AppFunction/_branches/plugincards/AppFCEV/localization/ts	
DIR_DEST=/home/susu/Desktop/SVN_HKMC/AppFunction/_branches/plugincards/AppFCEV/localization/qm

PREFIX=translation_
#declaration regions
SUFFIX=("ar" "en" "cs" "da" "es-eu" "es-na" "fr-eu" "fr-na" "it" "nl" "pl" "pt" "sk" "sv" "tr" "ru" "ko" "zh-cmn" "en-eu" "hung" "norwe" "jp")
# gen ".qm" file depend on region
for i in ${SUFFIX[@]}; do
	${BIN_GEN_QM} ${DIR_SRCS}/${PREFIX}${i}.ts -qm ${DIR_DEST}/${PREFIX}${i}.qm
done
