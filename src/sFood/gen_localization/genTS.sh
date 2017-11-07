#!/bin/bash

BIN_GEN_TS=/home/ak/Qt5.4.1/5.4/gcc_64/bin/./lupdate
DIR_SRCS=../Js/*.js

nation=("ar" "cs" "da" "de" "en" "en-ko" "es-eu" "es-na" "fr-eu" "fr-na" "it" "ko" "nl" "pl" "pt" "ru" "sk" "sv" "tr" "zh-cmn")
for i in ${nation[@]}; do
	echo $i
	$BIN_GEN_TS $DIR_SRCS -ts ../localization/ts/translation_$i.ts
done

