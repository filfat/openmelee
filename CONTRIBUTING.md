# Contributing

## Code style
Based on Yuzu's style-guide.

### General Rules
* Use namespaces often

### Naming Rules
* Functions: `PascalCase`
* Variables: `lower_case_underscored`. Prefix with `g_` if global.
* Classes: `PascalCase`
* Files and Directories: `lower_case_underscored`
* Namespaces: `PascalCase`.

### Indentation/Whitespace Style
Follow the indentation/whitespace style shown below. Do not use tabs, use 4-spaces instead.

### Comments
* For regular comments, use C++ style (`//`) comments, even for multi-line ones.
* For doc-comments (Doxygen comments), use `/// ` if it's a single line, else use the `/**` `*/` style featured in the example. Start the text on the second line, not the first containing `/**`.
* For items that are both defined and declared in two separate files, put the doc-comment only next to the associated declaration. (In a header file, usually.) Otherwise, put it next to the implementation. Never duplicate doc-comments in both places.

```cpp
// Includes should be sorted lexicographically
// STD includes first, then, library includes, and finally project includes
// No blank line between #includes (unless conditional #include presents)
#include <map>
#include <memory>
#include <nihstro/shared_binary.h>
#include "common/math_util.h"
#include "common/vector_math.h"
#include "video_core/pica.h"
#include "video_core/video_core.h"

namespace Example {
    // Namespace content is indented

    // Declare globals at the top
    int32_t g_foo = 0; // ALWAYS intitialize variables.
    int8_t* g_some_pointer = nullptr; // Use normalized types.

    /// A colorful enum.
    typedef enum {
        ColorRed,   ///< The color of fire.
        ColorGreen, ///< The color of grass.
        ColorBlue,  ///< Not actually the color of water.
    } SomeEnum;

    struct typedef {
        int32_t x = 0, y = 0; // ALWAYS try to intitialize member variables!
    } Position;

    // Use "typename" rather than "class" here
    void FooBar() {
        if (note == the_space_after_the_if) {
            CallAfunction();
        } else {
            // Use a space after the // when commenting
        }

        // Place a single space after the for loop semicolons, prefer after-increment
        for (int32_t i = 0; i < 25; i++) {
            // This is how we write loops
        }

        switch (var) {
            // Indentation for case label
            case 1: {
                int32_t case_var = (var + 3);
                DoSomething(case_var);
                break;
            }
            case 3:
                DoSomething(var);
                return;

            case 4:
                int32_t x = 0;
                [[fallthrough]]; // Explicit fall through
            case 5:
                DoSomethingElse();
                break;
            default:
                // Yes, even break for the last case
                break;
        }
    }
}
```