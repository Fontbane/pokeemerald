#include "global.h"
#include "graphics.h"
#include "mail.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "sprite.h"
#include "constants/species.h"

#define POKE_ICON_BASE_PAL_TAG 56000

struct MonIconSpriteTemplate
{
    const struct OamData *oam;
    const u8 *image;
    const union AnimCmd *const *anims;
    const union AffineAnimCmd *const *affineAnims;
    void (*callback)(struct Sprite *);
    u16 paletteTag;
};

// static functions
static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *, s16, s16, u8);

// .rodata

const u8 *const gMonIconTable[] =
{
    gMonIcon_Bulbasaur,
    gMonIcon_Bulbasaur,
    gMonIcon_Ivysaur,
    gMonIcon_Venusaur,
    gMonIcon_Charmander,
    gMonIcon_Charmeleon,
    gMonIcon_Charizard,
    gMonIcon_Squirtle,
    gMonIcon_Wartortle,
    gMonIcon_Blastoise,
    gMonIcon_Caterpie,
    gMonIcon_Metapod,
    gMonIcon_Butterfree,
    gMonIcon_Weedle,
    gMonIcon_Kakuna,
    gMonIcon_Beedrill,
    gMonIcon_Pidgey,
    gMonIcon_Pidgeotto,
    gMonIcon_Pidgeot,
    gMonIcon_Rattata,
    gMonIcon_Raticate,
    gMonIcon_Spearow,
    gMonIcon_Fearow,
    gMonIcon_Ekans,
    gMonIcon_Arbok,
    gMonIcon_Pikachu,
    gMonIcon_Raichu,
    gMonIcon_Sandshrew,
    gMonIcon_Sandslash,
    gMonIcon_NidoranF,
    gMonIcon_Nidorina,
    gMonIcon_Nidoqueen,
    gMonIcon_NidoranM,
    gMonIcon_Nidorino,
    gMonIcon_Nidoking,
    gMonIcon_Clefairy,
    gMonIcon_Clefable,
    gMonIcon_Vulpix,
    gMonIcon_Ninetales,
    gMonIcon_Jigglypuff,
    gMonIcon_Wigglytuff,
    gMonIcon_Zubat,
    gMonIcon_Golbat,
    gMonIcon_Oddish,
    gMonIcon_Gloom,
    gMonIcon_Vileplume,
    gMonIcon_Paras,
    gMonIcon_Parasect,
    gMonIcon_Venonat,
    gMonIcon_Venomoth,
    gMonIcon_Diglett,
    gMonIcon_Dugtrio,
    gMonIcon_Meowth,
    gMonIcon_Persian,
    gMonIcon_Psyduck,
    gMonIcon_Golduck,
    gMonIcon_Mankey,
    gMonIcon_Primeape,
    gMonIcon_Growlithe,
    gMonIcon_Arcanine,
    gMonIcon_Poliwag,
    gMonIcon_Poliwhirl,
    gMonIcon_Poliwrath,
    gMonIcon_Abra,
    gMonIcon_Kadabra,
    gMonIcon_Alakazam,
    gMonIcon_Machop,
    gMonIcon_Machoke,
    gMonIcon_Machamp,
    gMonIcon_Bellsprout,
    gMonIcon_Weepinbell,
    gMonIcon_Victreebel,
    gMonIcon_Tentacool,
    gMonIcon_Tentacruel,
    gMonIcon_Geodude,
    gMonIcon_Graveler,
    gMonIcon_Golem,
    gMonIcon_Ponyta,
    gMonIcon_Rapidash,
    gMonIcon_Slowpoke,
    gMonIcon_Slowbro,
    gMonIcon_Magnemite,
    gMonIcon_Magneton,
    gMonIcon_Farfetchd,
    gMonIcon_Doduo,
    gMonIcon_Dodrio,
    gMonIcon_Seel,
    gMonIcon_Dewgong,
    gMonIcon_Grimer,
    gMonIcon_Muk,
    gMonIcon_Shellder,
    gMonIcon_Cloyster,
    gMonIcon_Gastly,
    gMonIcon_Haunter,
    gMonIcon_Gengar,
    gMonIcon_Onix,
    gMonIcon_Drowzee,
    gMonIcon_Hypno,
    gMonIcon_Krabby,
    gMonIcon_Kingler,
    gMonIcon_Voltorb,
    gMonIcon_Electrode,
    gMonIcon_Exeggcute,
    gMonIcon_Exeggutor,
    gMonIcon_Cubone,
    gMonIcon_Marowak,
    gMonIcon_Hitmonlee,
    gMonIcon_Hitmonchan,
    gMonIcon_Lickitung,
    gMonIcon_Koffing,
    gMonIcon_Weezing,
    gMonIcon_Rhyhorn,
    gMonIcon_Rhydon,
    gMonIcon_Chansey,
    gMonIcon_Tangela,
    gMonIcon_Kangaskhan,
    gMonIcon_Horsea,
    gMonIcon_Seadra,
    gMonIcon_Goldeen,
    gMonIcon_Seaking,
    gMonIcon_Staryu,
    gMonIcon_Starmie,
    gMonIcon_Mrmime,
    gMonIcon_Scyther,
    gMonIcon_Jynx,
    gMonIcon_Electabuzz,
    gMonIcon_Magmar,
    gMonIcon_Pinsir,
    gMonIcon_Tauros,
    gMonIcon_Magikarp,
    gMonIcon_Gyarados,
    gMonIcon_Lapras,
    gMonIcon_Ditto,
    gMonIcon_Eevee,
    gMonIcon_Vaporeon,
    gMonIcon_Jolteon,
    gMonIcon_Flareon,
    gMonIcon_Porygon,
    gMonIcon_Omanyte,
    gMonIcon_Omastar,
    gMonIcon_Kabuto,
    gMonIcon_Kabutops,
    gMonIcon_Aerodactyl,
    gMonIcon_Snorlax,
    gMonIcon_Articuno,
    gMonIcon_Zapdos,
    gMonIcon_Moltres,
    gMonIcon_Dratini,
    gMonIcon_Dragonair,
    gMonIcon_Dragonite,
    gMonIcon_Mewtwo,
    gMonIcon_Mew,
    gMonIcon_Chikorita,
    gMonIcon_Bayleef,
    gMonIcon_Meganium,
    gMonIcon_Cyndaquil,
    gMonIcon_Quilava,
    gMonIcon_Typhlosion,
    gMonIcon_Totodile,
    gMonIcon_Croconaw,
    gMonIcon_Feraligatr,
    gMonIcon_Sentret,
    gMonIcon_Furret,
    gMonIcon_Hoothoot,
    gMonIcon_Noctowl,
    gMonIcon_Ledyba,
    gMonIcon_Ledian,
    gMonIcon_Spinarak,
    gMonIcon_Ariados,
    gMonIcon_Crobat,
    gMonIcon_Chinchou,
    gMonIcon_Lanturn,
    gMonIcon_Pichu,
    gMonIcon_Cleffa,
    gMonIcon_Igglybuff,
    gMonIcon_Togepi,
    gMonIcon_Togetic,
    gMonIcon_Natu,
    gMonIcon_Xatu,
    gMonIcon_Mareep,
    gMonIcon_Flaaffy,
    gMonIcon_Ampharos,
    gMonIcon_Bellossom,
    gMonIcon_Marill,
    gMonIcon_Azumarill,
    gMonIcon_Sudowoodo,
    gMonIcon_Politoed,
    gMonIcon_Hoppip,
    gMonIcon_Skiploom,
    gMonIcon_Jumpluff,
    gMonIcon_Aipom,
    gMonIcon_Sunkern,
    gMonIcon_Sunflora,
    gMonIcon_Yanma,
    gMonIcon_Wooper,
    gMonIcon_Quagsire,
    gMonIcon_Espeon,
    gMonIcon_Umbreon,
    gMonIcon_Murkrow,
    gMonIcon_Slowking,
    gMonIcon_Misdreavus,
    gMonIcon_UnownA,
    gMonIcon_Wobbuffet,
    gMonIcon_Girafarig,
    gMonIcon_Pineco,
    gMonIcon_Forretress,
    gMonIcon_Dunsparce,
    gMonIcon_Gligar,
    gMonIcon_Steelix,
    gMonIcon_Snubbull,
    gMonIcon_Granbull,
    gMonIcon_Qwilfish,
    gMonIcon_Scizor,
    gMonIcon_Shuckle,
    gMonIcon_Heracross,
    gMonIcon_Sneasel,
    gMonIcon_Teddiursa,
    gMonIcon_Ursaring,
    gMonIcon_Slugma,
    gMonIcon_Magcargo,
    gMonIcon_Swinub,
    gMonIcon_Piloswine,
    gMonIcon_Corsola,
    gMonIcon_Remoraid,
    gMonIcon_Octillery,
    gMonIcon_Delibird,
    gMonIcon_Mantine,
    gMonIcon_Skarmory,
    gMonIcon_Houndour,
    gMonIcon_Houndoom,
    gMonIcon_Kingdra,
    gMonIcon_Phanpy,
    gMonIcon_Donphan,
    gMonIcon_Porygon2,
    gMonIcon_Stantler,
    gMonIcon_Smeargle,
    gMonIcon_Tyrogue,
    gMonIcon_Hitmontop,
    gMonIcon_Smoochum,
    gMonIcon_Elekid,
    gMonIcon_Magby,
    gMonIcon_Miltank,
    gMonIcon_Blissey,
    gMonIcon_Raikou,
    gMonIcon_Entei,
    gMonIcon_Suicune,
    gMonIcon_Larvitar,
    gMonIcon_Pupitar,
    gMonIcon_Tyranitar,
    gMonIcon_Lugia,
    gMonIcon_HoOh,
    gMonIcon_Celebi,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_QuestionMark,
    gMonIcon_Treecko,
    gMonIcon_Grovyle,
    gMonIcon_Sceptile,
    gMonIcon_Torchic,
    gMonIcon_Combusken,
    gMonIcon_Blaziken,
    gMonIcon_Mudkip,
    gMonIcon_Marshtomp,
    gMonIcon_Swampert,
    gMonIcon_Poochyena,
    gMonIcon_Mightyena,
    gMonIcon_Zigzagoon,
    gMonIcon_Linoone,
    gMonIcon_Wurmple,
    gMonIcon_Silcoon,
    gMonIcon_Beautifly,
    gMonIcon_Cascoon,
    gMonIcon_Dustox,
    gMonIcon_Lotad,
    gMonIcon_Lombre,
    gMonIcon_Ludicolo,
    gMonIcon_Seedot,
    gMonIcon_Nuzleaf,
    gMonIcon_Shiftry,
    gMonIcon_Nincada,
    gMonIcon_Ninjask,
    gMonIcon_Shedinja,
    gMonIcon_Taillow,
    gMonIcon_Swellow,
    gMonIcon_Shroomish,
    gMonIcon_Breloom,
    gMonIcon_Spinda,
    gMonIcon_Wingull,
    gMonIcon_Pelipper,
    gMonIcon_Surskit,
    gMonIcon_Masquerain,
    gMonIcon_Wailmer,
    gMonIcon_Wailord,
    gMonIcon_Skitty,
    gMonIcon_Delcatty,
    gMonIcon_Kecleon,
    gMonIcon_Baltoy,
    gMonIcon_Claydol,
    gMonIcon_Nosepass,
    gMonIcon_Torkoal,
    gMonIcon_Sableye,
    gMonIcon_Barboach,
    gMonIcon_Whiscash,
    gMonIcon_Luvdisc,
    gMonIcon_Corphish,
    gMonIcon_Crawdaunt,
    gMonIcon_Feebas,
    gMonIcon_Milotic,
    gMonIcon_Carvanha,
    gMonIcon_Sharpedo,
    gMonIcon_Trapinch,
    gMonIcon_Vibrava,
    gMonIcon_Flygon,
    gMonIcon_Makuhita,
    gMonIcon_Hariyama,
    gMonIcon_Electrike,
    gMonIcon_Manectric,
    gMonIcon_Numel,
    gMonIcon_Camerupt,
    gMonIcon_Spheal,
    gMonIcon_Sealeo,
    gMonIcon_Walrein,
    gMonIcon_Cacnea,
    gMonIcon_Cacturne,
    gMonIcon_Snorunt,
    gMonIcon_Glalie,
    gMonIcon_Lunatone,
    gMonIcon_Solrock,
    gMonIcon_Azurill,
    gMonIcon_Spoink,
    gMonIcon_Grumpig,
    gMonIcon_Plusle,
    gMonIcon_Minun,
    gMonIcon_Mawile,
    gMonIcon_Meditite,
    gMonIcon_Medicham,
    gMonIcon_Swablu,
    gMonIcon_Altaria,
    gMonIcon_Wynaut,
    gMonIcon_Duskull,
    gMonIcon_Dusclops,
    gMonIcon_Roselia,
    gMonIcon_Slakoth,
    gMonIcon_Vigoroth,
    gMonIcon_Slaking,
    gMonIcon_Gulpin,
    gMonIcon_Swalot,
    gMonIcon_Tropius,
    gMonIcon_Whismur,
    gMonIcon_Loudred,
    gMonIcon_Exploud,
    gMonIcon_Clamperl,
    gMonIcon_Huntail,
    gMonIcon_Gorebyss,
    gMonIcon_Absol,
    gMonIcon_Shuppet,
    gMonIcon_Banette,
    gMonIcon_Seviper,
    gMonIcon_Zangoose,
    gMonIcon_Relicanth,
    gMonIcon_Aron,
    gMonIcon_Lairon,
    gMonIcon_Aggron,
    gMonIcon_Castform,
    gMonIcon_Volbeat,
    gMonIcon_Illumise,
    gMonIcon_Lileep,
    gMonIcon_Cradily,
    gMonIcon_Anorith,
    gMonIcon_Armaldo,
    gMonIcon_Ralts,
    gMonIcon_Kirlia,
    gMonIcon_Gardevoir,
    gMonIcon_Bagon,
    gMonIcon_Shelgon,
    gMonIcon_Salamence,
    gMonIcon_Beldum,
    gMonIcon_Metang,
    gMonIcon_Metagross,
    gMonIcon_Regirock,
    gMonIcon_Regice,
    gMonIcon_Registeel,
    gMonIcon_Kyogre,
    gMonIcon_Groudon,
    gMonIcon_Rayquaza,
    gMonIcon_Latias,
    gMonIcon_Latios,
    gMonIcon_Jirachi,
    gMonIcon_Deoxys,
    gMonIcon_Chimecho,
    gMonIcon_Egg,
    gMonIcon_UnownB,
    gMonIcon_UnownC,
    gMonIcon_UnownD,
    gMonIcon_UnownE,
    gMonIcon_UnownF,
    gMonIcon_UnownG,
    gMonIcon_UnownH,
    gMonIcon_UnownI,
    gMonIcon_UnownJ,
    gMonIcon_UnownK,
    gMonIcon_UnownL,
    gMonIcon_UnownM,
    gMonIcon_UnownN,
    gMonIcon_UnownO,
    gMonIcon_UnownP,
    gMonIcon_UnownQ,
    gMonIcon_UnownR,
    gMonIcon_UnownS,
    gMonIcon_UnownT,
    gMonIcon_UnownU,
    gMonIcon_UnownV,
    gMonIcon_UnownW,
    gMonIcon_UnownX,
    gMonIcon_UnownY,
    gMonIcon_UnownZ,
    gMonIcon_UnownExclamationMark,
    gMonIcon_UnownQuestionMark,
};

const u8 gMonIconPaletteIndices[] =
{
    [SPECIES_NONE] = 0,
    [SPECIES_TROTRUNK] = 1,
    [SPECIES_GARDENEIGH] = 1,
    [SPECIES_HORSE3] = 1,
    [SPECIES_FLAMMOO] = 0,
    [SPECIES_BISON] = 0,
    [SPECIES_TONROAST] = 0,
    [SPECIES_WOOSHELL] = 0,
    [SPECIES_SNAIL2] = 2,
    [SPECIES_ICECARGO] = 2,
    [SPECIES_CATRPILLOW] = 1,
    [SPECIES_QUILTALIS] = 1,
    [SPECIES_SLEEPIYAUN] = 0,
    [SPECIES_COLARVA] = 1,
    [SPECIES_VIBRAP] = 2,
    [SPECIES_PRISMOTH] = 2,
    [SPECIES_KITAIL] = 0,
    [SPECIES_KISTRUCT] = 0,
    [SPECIES_ROCLIPSE] = 0,
    [SPECIES_SCAFETYCHUK] = 2,
    [SPECIES_DIRTSKRT] = 1,
    [SPECIES_AUWAKIN] = 0,
    [SPECIES_WINKAUYIN] = 0,
    [SPECIES_KINYAUN] = 2,
    [SPECIES_HUGGLUT] = 2,
    [SPECIES_DENKI] = 2,
    [SPECIES_RUMBOLT] = 0,
    [SPECIES_THUGGLUT] = 2,
    [SPECIES_THIEVERINE] = 2,
    [SPECIES_PARACHNID] = 2,
    [SPECIES_DEPLOYDER] = 2,
    [SPECIES_ARACHILLES] = 2,
    [SPECIES_BEADRA] = 2,
    [SPECIES_BEADERMA] = 2,
    [SPECIES_GILAGON] = 2,
    [SPECIES_CLEFAIRY] = 0,
    [SPECIES_CLEFABLE] = 0,
    [SPECIES_VULPIX] = 2,
    [SPECIES_NINETALES] = 1,
    [SPECIES_KITTEA] = 0,
    [SPECIES_TABBREW] = 0,
    [SPECIES_SNOBAT] = 2,
    [SPECIES_GLACIBAT] = 2,
    [SPECIES_ODDISH] = 1,
    [SPECIES_GLOOM] = 0,
    [SPECIES_VILEPLUME] = 0,
    [SPECIES_MEMOROO] = 0,
    [SPECIES_POTOCAMPUS] = 0,
    [SPECIES_VENONAT] = 0,
    [SPECIES_VENOMOTH] = 2,
    [SPECIES_BITTLE] = 2,
    [SPECIES_GOARYU] = 2,
    [SPECIES_BAAZE] = 1,
    [SPECIES_EWEYE] = 1,
    [SPECIES_PSYDUCK] = 1,
    [SPECIES_GOLDUCK] = 2,
    [SPECIES_MANKEY] = 1,
    [SPECIES_PRIMEAPE] = 2,
    [SPECIES_GROWLITHE] = 0,
    [SPECIES_ARCANINE] = 0,
    [SPECIES_TYMPOLE] = 0,
    [SPECIES_PALPITOAD] = 0,
    [SPECIES_SEISMITOAD] = 0,
    [SPECIES_SOLOSIS] = 2,
    [SPECIES_DUOSION] = 2,
    [SPECIES_REUNICLUS] = 2,
    [SPECIES_TIMBURR] = 0,
    [SPECIES_GURDURR] = 2,
    [SPECIES_CONKELDURR] = 0,
    [SPECIES_PIGNET] = 1,
    [SPECIES_PIGOLD] = 1,
    [SPECIES_PIGORMET] = 1,
    [SPECIES_GOSLAKE] = 2,
    [SPECIES_ALGOOSE] = 2,
    [SPECIES_ROGGENROLA] = 1,
    [SPECIES_BOLDORE] = 1,
    [SPECIES_GIGALITH] = 1,
    [SPECIES_HAWBUD] = 0,
    [SPECIES_MAWTHORNE] = 0,
    [SPECIES_SLOWPOKE] = 0,
    [SPECIES_SLOWBRO] = 0,
    [SPECIES_MAGNEMITE] = 0,
    [SPECIES_MAGNETON] = 0,
    [SPECIES_ELGYEM] = 1,
    [SPECIES_BEHEEYEM] = 2,
    [SPECIES_YUEHFOE] = 2,
    [SPECIES_TRUBBISH] = 2,
    [SPECIES_GARBODOR] = 2,
    [SPECIES_JUNKING] = 2,
    [SPECIES_SCAFETY] = 2,
    [SPECIES_SHELLDER] = 2,
    [SPECIES_CLOYSTER] = 2,
    [SPECIES_CHARMELLO] = 2,
    [SPECIES_GOOLITE] = 2,
    [SPECIES_SCORCHUGAR] = 2,
    [SPECIES_ONIX] = 2,
    [SPECIES_LIQWIL] = 2,
    [SPECIES_QWILMARINE] = 1,
    [SPECIES_CLAUNCHER] = 2,
    [SPECIES_CLAWITZER] = 2,
    [SPECIES_FOONGUS] = 0,
    [SPECIES_AMOONGUSS] = 0,
    [SPECIES_CRANIAXE] = 0,
    [SPECIES_ADZKULL] = 1,
    [SPECIES_HALBERDOME] = 1,
    [SPECIES_AXEW] = 1,
    [SPECIES_FRAXURE] = 2,
    [SPECIES_HAXORUS] = 2,
    [SPECIES_LICKITUNG] = 1,
    [SPECIES_FUOCUB] = 2,
    [SPECIES_KOGOZHAR] = 2,
    [SPECIES_RHYHORN] = 1,
    [SPECIES_RHYDON] = 1,
    [SPECIES_CHANSEY] = 0,
    [SPECIES_TANGELA] = 0,
    [SPECIES_BRILLANEON] = 1,
    [SPECIES_HORSEA] = 0,
    [SPECIES_SEADRA] = 0,
    [SPECIES_PONDURR] = 0,
    [SPECIES_THALAGOS] = 0,
    [SPECIES_STARYU] = 2,
    [SPECIES_STARMIE] = 2,
    [SPECIES_MEOWPLE] = 0,
    [SPECIES_SCYTHER] = 1,
    [SPECIES_SAPPURR] = 2,
    [SPECIES_ELECTABUZZ] = 1,
    [SPECIES_MAGMAR] = 0,
    [SPECIES_SYROAR] = 2,
    [SPECIES_HAGATTO] = 2,
    [SPECIES_BLOOMOUSE] = 0,
    [SPECIES_LAMPPEST] = 0,
    [SPECIES_CHAIBULL] = 2,
    [SPECIES_DITTO] = 2,
    [SPECIES_EEVEE] = 2,
    [SPECIES_VAPOREON] = 0,
    [SPECIES_JOLTEON] = 0,
    [SPECIES_FLAREON] = 0,
    [SPECIES_PORYGON] = 0,
    [SPECIES_TAUROFLAGE] = 0,
    [SPECIES_CAMOTAURUS] = 0,
    [SPECIES_FLATYKE] = 2,
    [SPECIES_FLATERROR] = 2,
    [SPECIES_GLAST] = 0,
    [SPECIES_ACHILLAUNCH] = 1,
    [SPECIES_HIBERMITE] = 0,
    [SPECIES_WINTERM] = 0,
    [SPECIES_TERMAFROST] = 0,
    [SPECIES_GOOMY] = 0,
    [SPECIES_SLIGGOO] = 0,
    [SPECIES_GOODRA] = 2,
    [SPECIES_LICKI] = 2,
    [SPECIES_SKUNTRED] = 0,
    [SPECIES_CHUPARTI] = 1,
    [SPECIES_DEVASTAIL] = 1,
    [SPECIES_RAVAGON] = 1,
    [SPECIES_DIPZIP] = 1,
    [SPECIES_PUPULSE] = 1,
    [SPECIES_NEUROGON] = 1,
    [SPECIES_CLOUTYKE] = 2,
    [SPECIES_OVERCROSS] = 2,
    [SPECIES_DRAMETEON] = 2,
    [SPECIES_TINKERN] = 2,
    [SPECIES_GREMLEAF] = 2,
    [SPECIES_PUZZOWL] = 2,
    [SPECIES_DIURNOWL] = 2,
    [SPECIES_KERNOSE] = 0,
    [SPECIES_MAIZIC] = 0,
    [SPECIES_WITCHIK] = 1,
    [SPECIES_POLLURE] = 0,
    [SPECIES_LILLIPUP] = 2,
    [SPECIES_HERDIER] = 2,
    [SPECIES_STOUTLAND] = 0,
    [SPECIES_WARPHAN] = 0,
    [SPECIES_CLEFFA] = 0,
    [SPECIES_BITTO] = 1,
    [SPECIES_TOGEPI] = 2,
    [SPECIES_TOGETIC] = 2,
    [SPECIES_NATU] = 0,
    [SPECIES_XATU] = 0,
    [SPECIES_MAREEP] = 2,
    [SPECIES_FLAAFFY] = 0,
    [SPECIES_AMPHAROS] = 0,
    [SPECIES_BELLOSSOM] = 1,
    [SPECIES_MARILL] = 2,
    [SPECIES_AZUMARILL] = 2,
    [SPECIES_SUDOWOODO] = 1,
    [SPECIES_GRASTRO] = 1,
    [SPECIES_COSMOSS] = 1,
    [SPECIES_PHANTUMP] = 1,
    [SPECIES_TREVENANT] = 2,
    [SPECIES_COARSTOMP] = 2,
    [SPECIES_DENSTOMP] = 1,
    [SPECIES_SANDSTOMP] = 1,
    [SPECIES_YANMA] = 1,
    [SPECIES_WOOPER] = 0,
    [SPECIES_QUAGSIRE] = 0,
    [SPECIES_ESPEON] = 2,
    [SPECIES_UMBREON] = 2,
    [SPECIES_MURKROW] = 2,
    [SPECIES_SLOWKING] = 0,
    [SPECIES_MISDREAVUS] = 0,
    [SPECIES_UNOWN] = 0,
    [SPECIES_PUPPERMINT] = 0,
    [SPECIES_HUSKOOL] = 1,
    [SPECIES_PUPPERONI] = 0,
    [SPECIES_SALAMUTT] = 2,
    [SPECIES_DUNSPARCE] = 2,
    [SPECIES_GLIGAR] = 2,
    [SPECIES_STEELIX] = 0,
    [SPECIES_SNUBBULL] = 0,
    [SPECIES_GRANBULL] = 2,
    [SPECIES_QWILFISH] = 0,
    [SPECIES_SCIZOR] = 0,
    [SPECIES_ASSASSECT] = 1,
    [SPECIES_HERACROSS] = 2,
    [SPECIES_SNEASEL] = 0,
    [SPECIES_TEDDIURSA] = 0,
    [SPECIES_URSARING] = 2,
    [SPECIES_EDGEHOG] = 0,
    [SPECIES_LEDGEHOG] = 0,
    [SPECIES_SWINUB] = 2,
    [SPECIES_PILOSWINE] = 2,
    [SPECIES_CORSOLA] = 0,
    [SPECIES_REMORAID] = 0,
    [SPECIES_OCTILLERY] = 0,
    [SPECIES_FITTO] = 0,
    [SPECIES_MANTINE] = 2,
    [SPECIES_SKARMORY] = 0,
    [SPECIES_HOUNDOUR] = 0,
    [SPECIES_HOUNDOOM] = 0,
    [SPECIES_KINGDRA] = 0,
    [SPECIES_PHANPY] = 0,
    [SPECIES_DONPHAN] = 0,
    [SPECIES_PORYGON2] = 0,
    [SPECIES_DEDENNE] = 2,
    [SPECIES_SMEARGLE] = 1,
    [SPECIES_VOLEV] = 2,
    [SPECIES_KIXWOLE] = 2,
    [SPECIES_METOLE] = 1,
    [SPECIES_ELEKID] = 1,
    [SPECIES_MAGBY] = 1,
    [SPECIES_CLIFFOLE] = 1,
    [SPECIES_BLISSEY] = 1,
    [SPECIES_SIGILYPH] = 0,
    [SPECIES_DWEBBLE] = 2,
    [SPECIES_CRUSTLE] = 0,
    [SPECIES_LARVITAR] = 1,
    [SPECIES_PUPITAR] = 0,
    [SPECIES_TYRANITAR] = 1,
    [SPECIES_KLISH] = 0,
    [SPECIES_KLOSH] = 1,
    [SPECIES_CELEBI] = 1,
    [SPECIES_TREECKO] = 1,
    [SPECIES_GROVYLE] = 0,
    [SPECIES_SCEPTILE] = 1,
    [SPECIES_TORCHIC] = 0,
    [SPECIES_COMBUSKEN] = 0,
    [SPECIES_BLAZIKEN] = 0,
    [SPECIES_MUDKIP] = 0,
    [SPECIES_MARSHTOMP] = 0,
    [SPECIES_SWAMPERT] = 0,
    [SPECIES_MOOSWOLE] = 2,
    [SPECIES_CARIBUFF] = 2,
    [SPECIES_TEDDICHOO] = 2,
    [SPECIES_URSARTIC] = 2,
    [SPECIES_WURMPLE] = 0,
    [SPECIES_SILCOON] = 2,
    [SPECIES_BEAUTIFLY] = 0,
    [SPECIES_CASCOON] = 2,
    [SPECIES_DUSTOX] = 1,
    [SPECIES_LOTAD] = 1,
    [SPECIES_LOMBRE] = 1,
    [SPECIES_LUDICOLO] = 1,
    [SPECIES_SEEDOT] = 1,
    [SPECIES_NUZLEAF] = 1,
    [SPECIES_SHIFTRY] = 0,
    [SPECIES_NINCADA] = 1,
    [SPECIES_NINJASK] = 1,
    [SPECIES_SHEDINJA] = 1,
    [SPECIES_SKRELP] = 2,
    [SPECIES_DRAGALGE] = 2,
    [SPECIES_SHROOMISH] = 1,
    [SPECIES_BRELOOM] = 1,
    [SPECIES_SPINDA] = 1,
    [SPECIES_LUCHIK] = 0,
    [SPECIES_HAWLUCHA] = 0,
    [SPECIES_DEDEDENNE] = 2,
    [SPECIES_DUMMITE] = 0,
    [SPECIES_WAILMER] = 2,
    [SPECIES_WAILORD] = 0,
    [SPECIES_MAREANIE] = 0,
    [SPECIES_TOXAPEX] = 2,
    [SPECIES_KECLEON] = 1,
    [SPECIES_BALTOY] = 1,
    [SPECIES_CLAYDOL] = 0,
    [SPECIES_TURTONTI] = 0,
    [SPECIES_TURTONATOR] = 1,
    [SPECIES_SABLEYE] = 2,
    [SPECIES_GREMINI] = 0,
    [SPECIES_DHELMISE] = 0,
    [SPECIES_LUVDISC] = 0,
    [SPECIES_SHELLSHUCK] = 0,
    [SPECIES_STARAMBOLA] = 0,
    [SPECIES_FEEBAS] = 2,
    [SPECIES_MILOTIC] = 0,
    [SPECIES_DECEILLOW] = 0,
    [SPECIES_MAWLOW] = 0,
    [SPECIES_TRAPINCH] = 1,
    [SPECIES_VIBRAVA] = 1,
    [SPECIES_FLYGON] = 1,
    [SPECIES_KEYCRET] = 2,
    [SPECIES_CATALOCK] = 1,
    [SPECIES_CATCHULA] = 1,
    [SPECIES_NIGHTSNARE] = 0,
    [SPECIES_NUMMAID] = 1,
    [SPECIES_SOOTHAW] = 0,
    [SPECIES_SPHEAL] = 2,
    [SPECIES_SEALEO] = 2,
    [SPECIES_WALREIN] = 0,
    [SPECIES_SANDYGAST] = 1,
    [SPECIES_PALOSSAND] = 1,
    [SPECIES_SNORUNT] = 2,
    [SPECIES_GLALIE] = 0,
    [SPECIES_SNOWKI] = 1,
    [SPECIES_CRUMBOLT] = 0,
    [SPECIES_AZURILL] = 2,
    [SPECIES_MINERAIN] = 0,
    [SPECIES_DRIFTANGLE] = 2,
    [SPECIES_SHOROAM] = 0,
    [SPECIES_TRANCELL] = 0,
    [SPECIES_CARBINK] = 2,
    [SPECIES_MEDITITE] = 0,
    [SPECIES_MEDICHAM] = 0,
    [SPECIES_SWABLU] = 0,
    [SPECIES_ALTARIA] = 0,
    [SPECIES_VENOFLAP] = 0,
    [SPECIES_DUSKULL] = 0,
    [SPECIES_DUSCLOPS] = 0,
    [SPECIES_ROSELIA] = 0,
    [SPECIES_DRAMPA] = 2,
    [SPECIES_SYLVEON] = 2,
    [SPECIES_VULLABY] = 1,
    [SPECIES_JOLTIK] = 1,
    [SPECIES_GALVANTULA] = 2,
    [SPECIES_TROPIUS] = 1,
    [SPECIES_RUFFLET] = 0,
    [SPECIES_BRAVIARY] = 2,
    [SPECIES_MANDIBUZZ] = 2,
    [SPECIES_PANCHAM] = 0,
    [SPECIES_PANGORO] = 0,
    [SPECIES_SKELETUNA] = 0,
    [SPECIES_ABSOL] = 0,
    [SPECIES_SHUPPET] = 0,
    [SPECIES_BANETTE] = 0,
    [SPECIES_SEVIPER] = 2,
    [SPECIES_ZANGOOSE] = 0,
    [SPECIES_RELICANTH] = 1,
    [SPECIES_ARON] = 2,
    [SPECIES_LAIRON] = 2,
    [SPECIES_AGGRON] = 2,
    [SPECIES_CASTFORM] = 0,
    [SPECIES_VOLBEAT] = 0,
    [SPECIES_ILLUMISE] = 2,
    [SPECIES_TYRUNT] = 2,
    [SPECIES_TYRANTRUM] = 0,
    [SPECIES_AMAURA] = 0,
    [SPECIES_AURORUS] = 0,
    [SPECIES_RALTS] = 1,
    [SPECIES_KIRLIA] = 1,
    [SPECIES_GARDEVOIR] = 1,
    [SPECIES_BAGON] = 2,
    [SPECIES_SHELGON] = 2,
    [SPECIES_SALAMENCE] = 0,
    [SPECIES_BELDUM] = 0,
    [SPECIES_METANG] = 0,
    [SPECIES_METAGROSS] = 0,
    [SPECIES_REGIROCK] = 2,
    [SPECIES_REGICE] = 2,
    [SPECIES_REGISTEEL] = 2,
    [SPECIES_KYOGRE] = 2,
    [SPECIES_GROUDON] = 0,
    [SPECIES_RAYQUAZA] = 1,
    [SPECIES_LATIAS] = 0,
    [SPECIES_LATIOS] = 2,
    [SPECIES_JIRACHI] = 0,
    [SPECIES_DEOXYS] = 0,
    [SPECIES_CHIMECHO] = 0,
    [SPECIES_EGG] = 1,
    [SPECIES_UNOWN_B] = 0,
};

const struct SpritePalette gMonIconPaletteTable[] =
{
    { gMonIconPalettes[0], POKE_ICON_BASE_PAL_TAG + 0 },
    { gMonIconPalettes[1], POKE_ICON_BASE_PAL_TAG + 1 },
    { gMonIconPalettes[2], POKE_ICON_BASE_PAL_TAG + 2 },

// There are only 3 actual palettes. The following are unused
// and don't point to valid data.
    { gMonIconPalettes[3], POKE_ICON_BASE_PAL_TAG + 3 },
    { gMonIconPalettes[4], POKE_ICON_BASE_PAL_TAG + 4 },
    { gMonIconPalettes[5], POKE_ICON_BASE_PAL_TAG + 5 },
};

const struct OamData sMonIconOamData =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

// fastest to slowest

static const union AnimCmd sAnim_0[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_2[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_3[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_4[] =
{
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_FRAME(0, 29), // frame 0 is repeated
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const sMonIconAnims[] =
{
    sAnim_0,
    sAnim_1,
    sAnim_2,
    sAnim_3,
    sAnim_4,
};

static const union AffineAnimCmd sAffineAnim_0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_1[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 122),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const sMonIconAffineAnims[] =
{
    sAffineAnim_0,
    sAffineAnim_1,
};

const u16 sSpriteImageSizes[3][4] =
{
    // square
    {
         0x20, // 1×1
         0x80, // 2×2
        0x200, // 4×4
        0x800, // 8×8
    },

    // horizontal rectangle
    {
         0x40, // 2×1
         0x80, // 4×1
        0x100, // 4×2
        0x400, // 8×4
    },

    // vertical rectangle
    {
         0x40, // 1×2
         0x80, // 1×4
        0x100, // 2×4
        0x400, // 4×8
    },
};

u8 CreateMonIcon(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality, bool32 extra)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = GetMonIconPtr(species, personality, extra),
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    if (species > NUM_SPECIES)
        iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG;

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u8 sub_80D2D78(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, bool32 extra)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = NULL,
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    iconTemplate.image = GetMonIconTiles(species, extra);
    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u16 GetIconSpecies(u16 species, u32 personality)
{
    u16 result;

    if (species == SPECIES_UNOWN)
    {
        u16 letter = GetUnownLetterByPersonality(personality);
        if (letter == 0)
            letter = SPECIES_UNOWN;
        else
            letter += (SPECIES_UNOWN_B - 1);
        result = letter;
    }
    else
    {
        if (species > NUM_SPECIES)
            result = 260;
        else
            result = species;
    }

    return result;
}

u16 GetUnownLetterByPersonality(u32 personality)
{
    if (!personality)
        return 0;
    else
        return (((personality & 0x3000000) >> 18) | ((personality & 0x30000) >> 12) | ((personality & 0x300) >> 6) | (personality & 0x3)) % 0x1C;
}

u16 sub_80D2E84(u16 species)
{
    u16 value;

    if (MailSpeciesToSpecies(species, &value) == SPECIES_UNOWN)
    {
        if (value == 0)
            value += SPECIES_UNOWN;
        else
            value += (SPECIES_UNOWN_B - 1);
        return value;
    }
    else
    {
        if (species > (SPECIES_UNOWN_B - 1))
            species = SPECIES_UNOWN_J; // That's an oddly specific species.
        return GetIconSpecies(species, 0);
    }
}

const u8 *GetMonIconPtr(u16 species, u32 personality, bool32 extra)
{
    return GetMonIconTiles(GetIconSpecies(species, personality), extra);
}

void sub_80D2EF8(struct Sprite *sprite)
{
    sub_80D328C(sprite);
}

void LoadMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < 6; i++)
        LoadSpritePalette(&gMonIconPaletteTable[i]);
}

// unused
void SafeLoadMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = 260;
    palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void LoadMonIconPalette(u16 species)
{
    u8 palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void FreeMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < 6; i++)
        FreeSpritePaletteByTag(gMonIconPaletteTable[i].tag);
}

// unused
void SafeFreeMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = 260;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void FreeMonIconPalette(u16 species)
{
    u8 palIndex;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void sub_80D3014(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

const u8* GetMonIconTiles(u16 species, bool32 extra)
{
    const u8* iconSprite = gMonIconTable[species];
    if(species == SPECIES_DEOXYS && extra == TRUE)
    {
        iconSprite = (const u8*)(0x400 + (u32)iconSprite); //WTF?
    }
    return iconSprite;
}

void sub_80D304C(u16 offset)
{
    s32 i;
    const struct SpritePalette* monIconPalettePtr;

    if (offset <= 0xA0)
    {
        monIconPalettePtr = gMonIconPaletteTable;
        for(i = 5; i >= 0; i--)
        {
            LoadPalette(monIconPalettePtr->data, offset, 0x20);
            offset += 0x10;
            monIconPalettePtr++;
        }
    }
}

u8 GetValidMonIconPalIndex(u16 species)
{
    if (species > NUM_SPECIES)
        species = 260;
    return gMonIconPaletteIndices[species];
}

u8 sub_80D30A0(u16 species)
{
    return gMonIconPaletteIndices[species];
}

const u16* GetValidMonIconPalettePtr(u16 species)
{
    if (species > NUM_SPECIES)
        species = 260;
    return gMonIconPaletteTable[gMonIconPaletteIndices[species]].data;
}

u8 UpdateMonIconFrame(struct Sprite *sprite)
{
    u8 result = 0;

    if (sprite->animDelayCounter == 0)
    {
        s16 frame = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;

        switch (frame)
        {
        case -1:
            break;
        case -2:
            sprite->animCmdIndex = 0;
            break;
        default:
            RequestSpriteCopy(
                // pointer arithmetic is needed to get the correct pointer to perform the sprite copy on.
                // because sprite->images is a struct def, it has to be casted to (u8 *) before any
                // arithmetic can be performed.
                (u8 *)sprite->images + (sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] * frame),
                (u8 *)(OBJ_VRAM0 + sprite->oam.tileNum * TILE_SIZE_4BPP),
                sSpriteImageSizes[sprite->oam.shape][sprite->oam.size]);
            sprite->animDelayCounter = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration & 0xFF;
            sprite->animCmdIndex++;
            result = sprite->animCmdIndex;
            break;
        }
    }
    else
    {
        sprite->animDelayCounter--;
    }
    return result;
}

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *iconTemplate, s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;

    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[iconTemplate->oam->shape][iconTemplate->oam->size] };

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = 0xFFFF,
        .paletteTag = iconTemplate->paletteTag,
        .oam = iconTemplate->oam,
        .anims = iconTemplate->anims,
        .images = &image,
        .affineAnims = iconTemplate->affineAnims,
        .callback = iconTemplate->callback,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    gSprites[spriteId].images = (const struct SpriteFrameImage *)iconTemplate->image;
    return spriteId;
}

void sub_80D328C(struct Sprite *sprite)
{
    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] };
    sprite->images = &image;
    DestroySprite(sprite);
}

void sub_80D32C8(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}
