# HorrorHotelUE

Este proyecto es un juego de terror multijugador basado en el template de Top Down de Unreal Engine. A continuación, se describen brevemente las principales clases que conforman el proyecto.

### Instrucciones

- **Acceso al Juego**:
  - El proyecto se puede jugar desde el nivel **"GameplayMap_Multiplayer"**, Este nivel se puede probar con varios jugadores.

- **Objetivo del Juego**:
  - **Explora las Instalaciones**: Adéntrate en el misterioso hotel y desentraña sus secretos.
  - **Obtén las Llaves**: Busca y recolecta las llaves ocultas que necesitarás para progresar y desbloquear nuevas áreas.
  - **Escapa del Lugar**: Una vez que hayas reunido todas las llaves necesarias, encuentra la salida y escapa del hotel antes de que sea demasiado tarde.

- **Controles del Juego**:
  - **Movimiento del Personaje**: Usa el **clic izquierdo del ratón** para mover a tu personaje por el mapa.
  - **Recoger Objetos**: Interactúa con los objetos en el entorno para recogerlos y añadirlos a tu inventario.
  - **Soltar Objetos**: Gestiona tu inventario soltando objetos cuando sea necesario para adaptarte a las diferentes situaciones del juego.

¡Explora, resuelve y sobrevive! Disfruta de esta emocionante experiencia de juego multijugador y demuestra tus habilidades para escapar del terrorífico hotel. Si tienes alguna pregunta o necesitas ayuda adicional, no dudes en consultarme.

## Clases Principales


### 1. MultiplayerGameStateBase

`MultiplayerGameStateBase` es responsable de mantener y administrar el estado del juego multijugador, particularmente el seguimiento de las llaves recolectadas por los jugadores. Esta clase garantiza la sincronización adecuada del estado del juego entre el servidor y los clientes.

#### Atributos Principales:
- **KeysCount**: Contador de llaves que mantiene la cantidad de llaves recolectadas por los jugadores. Esta propiedad está replicada para asegurar que todos los clientes tengan el mismo valor.
- **MaxKeys**: Número máximo de llaves disponibles en el juego.
- **OnKeyCountChanged**: Delegado dinámico multicast que se dispara cuando el contador de llaves cambia, permitiendo actualizar la interfaz de usuario u otras mecánicas del juego en respuesta.

#### Métodos Principales:
- **AMultiplayerGameStateBase()**: Constructor de la clase que inicializa los valores por defecto.
- **AddKey()**: Método BlueprintCallable que incrementa el contador de llaves. Este método también dispara el delegado `OnKeyCountChanged` para notificar sobre cambios en el contador de llaves.
- **GetKeyCount()**: Método BlueprintCallable que devuelve el número actual de llaves recolectadas.
- **GetMaxKeys()**: Método BlueprintCallable que devuelve el número máximo de llaves disponibles en el juego.
- **OnRep_KeyCount()**: Método que se llama automáticamente cuando la propiedad `KeysCount` se replica y cambia, asegurando que las actualizaciones del contador de llaves se reflejen correctamente en todos los clientes.


### 2. MultiPlayerController

`MultiPlayerController` es el controlador principal para los jugadores en el juego multijugador. Hereda de `ATP_TopDownPlayerController` y gestiona diversas funcionalidades como las interacciones, la UI del jugador y el manejo de ítems.

#### Atributos Principales:

- **SetInteractAction**: Acción de entrada para la interacción.
- **ItemToInteract**: Referencia al ítem actual con el que el jugador puede interactuar.
- **PlayerUIManagerComponent**: Componente que gestiona la interfaz de usuario del jugador.
- **BP_PickableItemClass**: Clase del Blueprint `BP_PickableItem` que será spawneada.

#### Métodos Principales:

- **AMultiPlayerController()**: Constructor de la clase.
- **SetupInputComponent()**: Configura los componentes de entrada y las acciones.
- **BeginPlay()**: Inicializa el componente de UI del jugador.
- **OnInteract()**: Maneja la interacción del jugador con un ítem interactuable.
- **Server_PlayerInteract(AInteractableItem* InItem)**: RPC para manejar la interacción del ítem en el servidor.
- **ShowInteractionWidget(bool bShow)**: Muestra u oculta el widget de interacción.
- **SetInteractionItem(AInteractableItem* InItem)**: Establece el ítem actual con el que el jugador puede interactuar.
- **DropItem(int32 ItemIndex)**: Permite al jugador soltar un ítem en su posición actual.
- **Server_DropItem(int32 ItemIndex, FVector InLocation)



### 3. MultiPlayerCharacter
`MultiPlayerCharacter` es la clase que representa al personaje del jugador. Hereda las funcionalidades del template de Top Down y añade capacidades específicas para el juego multijugador, como la interacción con objetos y la recolección de llaves.

#### Atributos Principales:

- **CollisionComponent**: Componente de colisión del personaje, utilizado para detectar superposiciones con otros actores.

#### Métodos Principales:

- **AMultiPlayerCharacter()**: Constructor de la clase que establece los valores por defecto para las propiedades del personaje.
- **BeginPlay()**: Método llamado cuando el juego comienza o el actor es spawneado por primera vez. Configura la lógica inicial del personaje.
- **Tick(float DeltaSeconds)**: Método llamado cada frame para actualizar el estado del personaje.
- **OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)**: Método llamado cuando el componente de colisión del personaje comienza a superponerse con otro actor.
- **OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)**: Método llamado cuando el componente de colisión del personaje deja de superponerse con otro actor.

### 4. InteractuableItem

`InteractuableItem` es la clase base para todos los ítems que pueden ser interactuados en el juego. Define la lógica básica para la interacción y la replicación de los ítems.

#### Funcionalidades Clave:
- **OnInteraction**: Método virtual que define la lógica de interacción, sobrescrito por clases derivadas.
- **GetLifetimeReplicatedProps**: Configura las propiedades para la replicación.

### 5. KeyItem

`KeyItem` hereda de `InteractuableItem` y representa las llaves que los jugadores deben recoger. Incluye la lógica específica para incrementar el conteo de llaves y destruirse tras ser recogida.

### 6. PickableItem

`PickableItem` hereda de `InteractuableItem` y representa ítems que pueden ser recogidos y soltados por los jugadores. Incluye un evento implementable en Blueprint (`ItemPickedUpEvent`) que se invoca cuando el ítem es recogido.

### 7. InteractableDoor

`InteractableDoor` hereda de `InteractuableItem` y representa las puertas en el juego. Se encarga de abrirse cuando los jugadores tienen la cantidad necesaria de llaves. Incluye un evento implementable en Blueprint (`OpenDoorEvent`) que se invoca cuando la puerta es abierta.

### Relación entre las Clases

- **Herencia**: `KeyItem`, `PickableItem` y `InteractableDoor` heredan de `InteractuableItem`, lo que les permite compartir y extender la funcionalidad básica de un ítem interactuable.
- **Especialización**: Cada clase derivada (`KeyItem`, `PickableItem`, `InteractableDoor`) añade su propia lógica específica y eventos únicos, como recoger llaves, soltar ítems, y abrir puertas.

## Herencia del Template de Top Down

Este proyecto hereda del template de Top Down de Unreal Engine, que proporciona una vista desde arriba del personaje y un esquema de control básico. El template se ha expandido para incluir funcionalidades multijugador y nuevas mecánicas de juego específicas del género de terror, como la recolección de llaves y la interacción con objetos y puertas.