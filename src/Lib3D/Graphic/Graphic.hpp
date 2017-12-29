#ifndef			GRAPHIC_H
# define		GRAPHIC_H

# include		<map>
# include		"Lib3D.hpp"
# include		"Node.hpp"
# include		"Camera.hpp"

namespace indie
{

class				Graphic : public Lib3D
{
  public:
    /* Structure holding a 3d mesh in memory */
    struct			MeshBlitSpec
    {
      std::string		path;
      std::string		texture;
      int			ID;
      int			parentID;
      int			frameLoop;
      int			animationSpeed;
      Position			scale;
      Position			position;
      Position			rotation;
      MeshBlitSpec();
    };

    struct			GUIBlitSpec
    {
      int			eventID;

      wchar_t			*primaryText;
      Position			uppLeftPos;
      wchar_t			*secondaryText;
      bool			trigger;
				GUIBlitSpec(const int eventID = -1,
					    wchar_t *primaryText = 0,
					    const Position& pos = Position(0, 0, 0),
					    wchar_t *secondaryText = 0,
					    bool trigger = true);
    };

    static const int		_CAMERA_ID;

  private:
    using eventMap_t = std::map<indie::EventContext, Sptr<AEventReceiver>>;

    static const std::string		_LEMMINGS_FONT;
    static const std::string		_BUTTON_BG;

    /* Structure holding a 2D image in memory */
    struct				Img2D
    {
      irr::video::ITexture		*img;
      irr::core::position2d<irr::s32>	uppLeftPos;
      irr::core::rect<irr::s32>		imgRect;
      irr::video::SColor		color;
    };
    std::vector<Img2D>			_img2DTab;

    Sptr<Camera>			_camera;
    irr::gui::IGUIEnvironment		*_gui;
    irr::gui::IGUIFont			*_font;
    irr::gui::IGUISkin			*_skin;
    bool				_state;
    eventMap_t				_eventReceiverTab;
    Sptr<AEventReceiver>		_currEventReceiver;

  /* Init.cpp */
    void			initGui();
    void			initEventReceiverTab();

    void			displayImg2D();
    void			addImgToButton(irr::gui::IGUIButton *,
					       const std::string&);
  public:
  				Graphic();
				~Graphic();

    static void				stringToWide(const std::string& src,
    						     wchar_t *dest);
    static const irr::core::vector3df	posToVector3df(const Position&);

    bool		getState() const;
    void		display();
    void		blitImage(const std::string& path,
				  const Position& pos);
    void		blitText(const GUIBlitSpec& blitSPec);
    void 		blitButton(const GUIBlitSpec& blitSpec);
    void		blitCheckbox(const GUIBlitSpec& blitSpec);
    void		blitMesh(const MeshBlitSpec& blitSpec);
    void		clearScreen();
    void		quit();
    void		setVisible(const int nodeID, bool val);
    void		setCurrEventReceiver(EventContext);
    Sptr<AEventReceiver> getCurrEventReceiver() const;
    Position		getCameraPosition() const;
    void		setCamera(const Position&);
    void		setCameraPos(const Position&);
    irr::scene::ISceneNode	*getNodeByID(const int);
    int			getNodeID();
    irr::scene::ISceneNode	*getRootSceneNode();
    irr::scene::ISceneManager	*getSceneManager();
    void		addImgTab(std::vector<Img2D>);
    void		eraseNode(const int id);
};

} // End of namespace

#endif			/* !GRAPHIC_H */