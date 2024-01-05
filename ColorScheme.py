import json

def generate_color_h(json_data):
    color_h_content = """\
static char normfgcolor[]                = "{}";
static char normbgcolor[]                = "{}";
static char normbordercolor[]            = "{}";
static char normfloatcolor[]             = "{}";

static char selfgcolor[]                 = "{}";
static char selbgcolor[]                 = "{}";
static char selbordercolor[]             = "{}";
static char selfloatcolor[]              = "{}";

static char titlenormfgcolor[]           = "{}";
static char titlenormbgcolor[]           = "{}";
static char titlenormbordercolor[]       = "{}";
static char titlenormfloatcolor[]        = "{}";

static char titleselfgcolor[]            = "{}";
static char titleselbgcolor[]            = "{}";
static char titleselbordercolor[]        = "{}";
static char titleselfloatcolor[]         = "{}";

static char tagsnormfgcolor[]            = "{}";
static char tagsnormbgcolor[]            = "{}";
static char tagsnormbordercolor[]        = "{}";
static char tagsnormfloatcolor[]         = "{}";

static char tagsselfgcolor[]             = "{}";
static char tagsselbgcolor[]             = "{}";
static char tagsselbordercolor[]         = "{}";
static char tagsselfloatcolor[]          = "{}";

static char hidfgcolor[]                 = "{}";
static char hidbgcolor[]                 = "{}";
static char hidbordercolor[]             = "{}";
static char hidfloatcolor[]              = "{}";

static char urgfgcolor[]                 = "{}";
static char urgbgcolor[]                 = "{}";
static char urgbordercolor[]             = "{}";
static char urgfloatcolor[]              = "{}";
""".format(
        json_data["colors"]["color0"],
        json_data["colors"]["color15"],
        json_data["colors"]["color0"],
        json_data["colors"]["color0"],
        
        json_data["colors"]["color15"],
        json_data["colors"]["color1"],
        json_data["colors"]["color1"],
        json_data["colors"]["color1"],
        
        json_data["colors"]["color15"],
        json_data["colors"]["color0"],
        json_data["colors"]["color0"],
        json_data["colors"]["color0"],
        
        json_data["colors"]["color15"],
        json_data["colors"]["color1"],
        json_data["colors"]["color1"],
        json_data["colors"]["color1"],
        
        json_data["colors"]["color15"],
        json_data["colors"]["color0"],
        json_data["colors"]["color0"],
        json_data["colors"]["color0"],
        
        json_data["colors"]["color15"],
        json_data["colors"]["color1"],
        json_data["colors"]["color1"],
        json_data["colors"]["color1"],
        
        json_data["colors"]["color15"],
        json_data["colors"]["color0"],
        json_data["colors"]["color0"],
        json_data["colors"]["color0"],
        
        json_data["colors"]["color1"],
        json_data["colors"]["color15"],
        json_data["colors"]["color1"],
        json_data["colors"]["color1"],
    )
    return color_h_content

# Read color.json
with open("/home/yash/.cache/wal/colors.json", "r") as json_file:
    color_data = json.load(json_file)
    print(color_data["wallpaper"])

# Generate color.h content
color_h_content = generate_color_h(color_data)

# Write to color.h
with open("/home/yash/dotfiles2/dwm-flexipatch/color.h", "w") as color_h_file:
    color_h_file.write(color_h_content)